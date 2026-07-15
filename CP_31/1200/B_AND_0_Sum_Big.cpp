#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

// ll fact(ll n){
//     return 0;
// }

ll power(ll n, ll k) {
    if (k == 0) return 1;

    ll half = power(n, k / 2);
    
    ll res = (half * half) % MOD;
    if (k % 2 != 0) {
        res = (res * n) % MOD;
    }

    return res;
}

void solve(){
    ll n, k;
    cin >> n >> k;

    cout << power(n, k) << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}