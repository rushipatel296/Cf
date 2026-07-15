#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int longest = 1;
    int cur = 1;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i - 1]){
            cur++;
        }else{
            cur = 1;
        }
        longest = max(cur, longest);
    }
    cout << longest + 1 << endl;


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