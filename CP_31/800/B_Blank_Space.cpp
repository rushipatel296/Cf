#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    int longest = -INF;
    int cur = 0;

    for(int i = 0; i < n; i++){
        int ele; 
        cin >> ele;
        if(ele == 0) {
            cur++;
        }else{
            cur = 0;
        }
        longest = max(longest, cur);
    }
    cout << longest << endl;
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