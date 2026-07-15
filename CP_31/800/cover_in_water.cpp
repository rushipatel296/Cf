#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    // Write your solution here
    int n;
    string s;

    //n is the length of string s
    cin >> n;
    cin >> s;
    int consec = 0;
    int dot_cnt = 0;
    int cur = 0;
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == '.'){
            dot_cnt++;
            cur++;
        }else{
            cur = 0;
        }
        consec = max(consec, cur);
        if(consec == 3) break;
        
        // if(s[i] == '.' && s[i - 1] == '.'){
        //     cur++;
        //     consec = max(cur, consec);
        //     // if(consec == 3) break;
        // }else{
        //     cur = 0;
        // }
    }
    // if(s[0] == '.') dot_cnt++;
    // cout << "Debug - Consecutive Dot count : " << consec << endl;
    if(consec >= 3){
        cout << "2" << endl;
    }else{
        cout << dot_cnt << endl;
    }
    return;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}