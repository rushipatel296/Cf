#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll a, b;

    cin >> a >> b;
    ll ans = INT_MAX;

    for(ll addition = 0; addition <= 31; addition++){
        ll newB = b + addition;
        ll ops = addition;
        ll n = a;
        if(newB == 1) continue;
        while(n > 0){
            n = n / newB;
            ops++;
        }

        ans = min(ans, ops);
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