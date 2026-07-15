#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    long long n, w;
    cin >> n >> w;

    //we need to make as many (w - 1) sized windows as possible
    long long ans = (n / w) * (w - 1) + (n % w);

    cout << ans << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}