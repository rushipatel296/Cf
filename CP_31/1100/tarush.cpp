#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, s;
    
    cout << "Enter number of microbes available     : "; cin >> a;
    cout << "Enter number of numbered traits        : "; cin >> b;
    cout << "Enter number of unnumbered traits (d/u): "; cin >> c;
    cout << "Enter number of microbes to select     : "; cin >> s;
    while(s < 1 || s > a){
        cout << "  Invalid! Must be between 1 and " << a << ": ";
        cin >> s;
    }

    // ── FIX: use vectors instead of VLAs ──
    vector<vector<int>>    trait(b + c, vector<int>(a, 0));
    vector<vector<double>> range(b,     vector<double>(2, 0));

    // ── Input ranges ──
    cout << "\n--- Enter Target Ranges for Numbered Traits ---\n";
    for(int i = 0; i < b; i++){
        cout << "  Trait #" << (i+1) << " -> Lower bound: "; cin >> range[i][0];
        cout << "  Trait #" << (i+1) << " -> Upper bound: "; cin >> range[i][1];
        while(range[i][1] < range[i][0]){
            cout << "  Invalid! Upper must be >= Lower. Re-enter: ";
            cin >> range[i][1];
        }
    }

    // ── Input microbes ──
    for(int j = 0; j < a; j++){
        cout << "\n--- Microbe #" << (j+1) << " ---\n";
        for(int i = 0; i < b; i++){
            cout << "  Numbered trait   #" << (i+1) << ": "; cin >> trait[i][j];
        }
        for(int i = 0; i < c; i++){
            int val;
            cout << "  Unnumbered trait #" << (i+1) << " (0=undesired, 1=neutral, 2=desired): ";
            cin >> val;
            while(val < 0 || val > 2){
                cout << "  Invalid! Enter 0, 1 or 2: "; cin >> val;
            }
            trait[b + i][j] = val;
        }
    }

    // ── Display Trait Table ──
    cout << "\n--- Trait Table ---\n";
    cout << "                ";
    for(int j = 0; j < a; j++) cout << "M" << (j+1) << "\t";
    cout << "\n";
    for(int i = 0; i < b; i++){
        cout << "Trait     #" << (i+1) << "  : ";
        for(int j = 0; j < a; j++) cout << trait[i][j] << "\t";
        cout << "\n";
    }
    for(int i = 0; i < c; i++){
        cout << "D/U Trait #" << (i+1) << "  : ";
        for(int j = 0; j < a; j++){
            if      (trait[b+i][j] == 0) cout << "U\t";
            else if (trait[b+i][j] == 2) cout << "D\t";
            else                          cout << "N\t";
        }
        cout << "\n";
    }

    // ── Display Range Table ──
    cout << "\n--- Target Range Table ---\n";
    cout << "                Lower\tUpper\n";
    for(int i = 0; i < b; i++)
        cout << "Trait     #" << (i+1) << "  : " << range[i][0] << "\t" << range[i][1] << "\n";

    // ── Scoring lambda (now captures vectors — no error) ──
    auto score_combo = [&](vector<int>& cm) -> int {
        int score = 0;
        for(int t = 0; t < b; t++){
            double avg = 0;
            for(int idx : cm) avg += trait[t][idx];
            avg /= s;
            if(avg >= range[t][0] && avg <= range[t][1]) score += 20;
        }
        bool hasDesired = false;
        for(int t = b; t < b+c && !hasDesired; t++)
            for(int idx : cm)
                if(trait[t][idx] == 2){ hasDesired = true; break; }
        if(hasDesired) score += 20;

        bool hasUndesired = false;
        for(int t = b; t < b+c && !hasUndesired; t++)
            for(int idx : cm)
                if(trait[t][idx] == 0){ hasUndesired = true; break; }
        if(!hasUndesired) score += 20;
        return score;
    };

    // ── Next combination (lexicographic) ──
    auto next_combo = [&](vector<int>& cm) -> bool {
        int i = s - 1;
        while(i >= 0 && cm[i] == a - s + i) i--;
        if(i < 0) return false;
        cm[i]++;
        for(int x = i+1; x < s; x++) cm[x] = cm[x-1] + 1;
        return true;
    };

    // ── Pass 1: find MAX score ──
    int MAX = -1;
    vector<int> combo(s);
    iota(combo.begin(), combo.end(), 0);
    do {
        int sc = score_combo(combo);
        if(sc > MAX) MAX = sc;
    } while(next_combo(combo));

    // ── Pass 2: collect all combos matching MAX ──
    vector<vector<int>> optimal;
    iota(combo.begin(), combo.end(), 0);
    do {
        if(score_combo(combo) == MAX)
            optimal.push_back(combo);
    } while(next_combo(combo));

    // ── Output ──
    auto label = [](int v){ return v==2?"D": v==0?"U":"N"; };

    cout << "\n╔══════════════════════════════════════════╗\n";
    cout << "║         ALL OPTIMAL COMBINATIONS         ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
    cout << "  Total microbes available    : " << a << "\n";
    cout << "  Microbes selected at a time : " << s << "\n";
    cout << "  Best Score                  : " << MAX << " / " << (b+2)*20 << " points\n";
    cout << "  Total optimal combos found  : " << optimal.size() << "\n";
    cout << string(50, '-') << "\n";

    int count = 1;
    for(auto& cm : optimal){
        cout << "\n  Combo #" << count++ << " -> ";
        for(int idx : cm) cout << "M" << (idx+1) << " ";
        cout << "\n";
        for(int t = 0; t < b; t++){
            double avg = 0;
            for(int idx : cm) avg += trait[t][idx];
            avg /= s;
            string st = (avg >= range[t][0] && avg <= range[t][1]) ? "PASS" : "FAIL";
            cout << "    Trait #" << (t+1) << ": avg = " << fixed << setprecision(2)
                 << avg << "  [" << range[t][0] << " - " << range[t][1] << "]  " << st << "\n";
        }
        for(int t = b; t < b+c; t++){
            cout << "    D/U Trait #" << (t-b+1) << ":  ";
            for(int idx : cm)
                cout << "M" << (idx+1) << "=" << label(trait[t][idx]) << "  ";
            cout << "\n";
        }
        cout << string(50, '-') << "\n";
    }

    cout << "\n==============================================\n";
    return 0;
}