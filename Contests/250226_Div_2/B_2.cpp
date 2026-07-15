#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int sum = 0;
    vector<int> reductions;
    
    // Calculate initial sum and collect maximum possible reductions for each digit
    for (int i = 0; i < s.length(); i++) {
        int d = s[i] - '0';
        sum += d;
        
        if (i == 0) {
            // Leading digit can only be reduced down to 1
            reductions.push_back(d - 1);
        } else {
            // Non-leading digits can be reduced down to 0
            reductions.push_back(d);
        }
    }
    
    // If it's already beautiful, 0 moves are required
    if (sum <= 9) {
        cout << 0 << "\n";
        return;
    }
    
    // Sort reductions in descending order to pick the most impactful ones first
    sort(reductions.rbegin(), reductions.rend());
    
    int ans = 0;
    for (int r : reductions) {
        sum -= r;
        ans++;
        if (sum <= 9) {
            break;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}