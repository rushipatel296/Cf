#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n;
    cin >> n;

    ll ans = 337;
    ans = (ans * n) % MOD;
    ans = (ans * (n + 1)) % MOD;
    ans = (ans * ((4 * n - 1) % MOD)) % MOD; 

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