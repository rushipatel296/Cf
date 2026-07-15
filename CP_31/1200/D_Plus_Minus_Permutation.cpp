#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;

    ll a = n / x;
    ll b = n / y;
    ll c = n / lcm(x, y);

    ll p = a - c;
    ll q = b - c;

    ll sum = 0;
    sum += (n * (n + 1)) / 2;
    sum -= ((n - p) * (n - p + 1)) / 2;

    sum -= (q * (q + 1)) / 2;

    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}