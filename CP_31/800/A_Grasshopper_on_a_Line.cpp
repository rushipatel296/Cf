#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int x, k;
    cin >> x >> k;

    bool solved = false;
    int cur_pos = 0;
    vector<int> ans;

    while(!solved){
        if(cur_pos == x){
            solved = true;
            break;
        }

        for(int i = x; i >= 0; i--){
            int d = abs(i - cur_pos);
            if(d % k != 0){
                //we can jump to i
                ans.push_back(d);
                cur_pos = i;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}