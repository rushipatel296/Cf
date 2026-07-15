#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
    long long n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<long long> prefix(n);
    prefix[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }

    long long total = prefix[n-1];

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;

        long long subarr = prefix[r] - (l > 0 ? prefix[l-1] : 0);
        long long replaced = 1LL * (r - l + 1) * k;

        long long new_sum = total - subarr + replaced;

        if(new_sum % 2) cout << "YES\n";
        else cout << "NO\n";
    }
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