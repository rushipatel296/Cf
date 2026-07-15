#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    int open_count = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            open_count++;
        }else{
            if(open_count > 0){
                open_count--;
            }else{
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}