#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;


void solve(){
    string s;
    cin >> s;

    int n = s.size();

    if(s[0] != s[n - 1]){
        if(s[0] == 'a'){
            s[0] = 'b';
        }else{
            s[0] = 'a';
        }
    }
    cout << s << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}