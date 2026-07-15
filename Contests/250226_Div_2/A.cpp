#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, d, m;
    cin >> n >> m >> d;

    // ((n % (x + 1) > 0) ? 1 : 0)
    int x = (d / m);
    int ans = (n / (x + 1)) + ((n % (x + 1) > 0) ? 1 : 0);
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