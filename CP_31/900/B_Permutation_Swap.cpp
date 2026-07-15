#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n ;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        int delta = abs(arr[i] - i - 1);
        ans = gcd(delta, ans);
    }

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