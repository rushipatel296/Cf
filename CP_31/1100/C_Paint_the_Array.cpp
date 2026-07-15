#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll g1 = 0, g2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) g1 = __gcd(g1, arr[i]);
        else g2 = __gcd(g2, arr[i]);
    }

    // Try G1: It divides all even-indexed elements. 
    bool ok1 = true;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] % g1 == 0) {
            ok1 = false;
            break;
        }
    }
    if (ok1) {
        cout << g1 << endl;
        return;
    }

    // Try G2: It divides all odd-indexed elements. 
    bool ok2 = true;
    for (int i = 0; i < n; i += 2) {
        if (arr[i] % g2 == 0) {
            ok2 = false;
            break;
        }
    }
    if (ok2) {
        cout << g2 << endl;
        return;
    }

    cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}