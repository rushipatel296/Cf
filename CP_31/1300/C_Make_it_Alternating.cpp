#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 998244353;



void solve(){
    string s;
    cin >> s;

    int n = s.size();
    vector<ll> fact(n + 1);
    fact[0] = 1;

    for(int i = 1; i <= n; i++){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    ll removals = 0;
    ll selections = 1;
    int L = 1;

    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            removals += L - 1; // window len = L, we remove L - 1 elements  
            selections = (selections * L) % MOD; // number of selections = L C (L - 1) = L 
            L = 1;
        }else{
            L++;
        }
    }
    removals += L - 1; // window len = L, we remove L - 1 elements  
    selections = (selections * L) % MOD;

    ll ways = (1LL * selections * fact[removals]) % MOD;


    cout << removals << " " << ways << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}