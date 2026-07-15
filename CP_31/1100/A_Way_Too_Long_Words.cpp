#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;
    string ans = s;
    if(s.size() > 10){
        int size = s.size() - 2;
        cout << s[0] << size << s[s.size() - 1] << endl;
    }else{
        cout << s << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}