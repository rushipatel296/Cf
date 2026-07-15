#include <bits/stdc++.h>
using namespace std;

// Global boolean arrays to avoid O(max_val) initialization per test case
bool local_seen[1000005];
bool global_seen[1000005];

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> lst(n);
    
    for(int k = 0; k < n; k++){
        int size;
        cin >> size;
        vector<int> l(size);
        for(int i = 0; i < size; i++){
            cin >> l[i];
        }

        reverse(l.begin(), l.end());
        
        vector<int> m;
        vector<int> local_visited; // Keep track to reset fast
        for(int i = 0; i < size; i++){
            if(!local_seen[l[i]]){
                m.push_back(l[i]);
                local_seen[l[i]] = true;
                local_visited.push_back(l[i]);
            }
        }
        // Clean up local_seen for the next iteration
        for(int x : local_visited) local_seen[x] = false;
        
        lst[k] = m;
    }

    vector<int> ans;
    vector<bool> used(n, false);
    vector<int> global_visited; // Keep track to reset fast

    // Pick the best array step-by-step
    for(int step = 0; step < n; step++){
        int best_idx = -1;
        vector<int> best_effective;
        
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            
            // Calculate what this array would actually contribute right now
            vector<int> current_effective;
            for(int x : lst[i]){
                if(!global_seen[x]){
                    current_effective.push_back(x);
                }
            }

            // If it's the first one we check, or it's lexicographically smaller
            if(best_idx == -1 || current_effective < best_effective){
                best_effective = current_effective;
                best_idx = i;
            }
        }

        used[best_idx] = true;
        // Commit the best effective contribution to our answer
        for(int x : best_effective){
            ans.push_back(x);
            global_seen[x] = true;
            global_visited.push_back(x);
        }
    }

    // Clean up global_seen for the next test case
    for(int x : global_visited) global_seen[x] = false;

    // Output
    // cout << "ANS : " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}