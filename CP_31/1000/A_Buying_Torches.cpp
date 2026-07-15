#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    ll sticks_needed = k * (y + 1) - 1;
    ll sticks_per_trade = x - 1;

    ll trade1 = (sticks_needed + sticks_per_trade  - 1) / sticks_per_trade;
    ll ans = trade1 + k;
    cout  << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}