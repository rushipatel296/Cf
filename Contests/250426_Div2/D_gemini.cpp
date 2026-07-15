#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // P will store pairs of {Prefix Sum, Original Index}
    // We only need prefix sums P_0 up to P_{n-1}
    vector<pair<long long, int>> P(n);
    long long current_sum = 0;
    
    P[0] = {0, 0}; // P_0 is exactly 0
    for (int i = 1; i < n; i++) {
        current_sum += a[i - 1];
        P[i] = {current_sum, i};
    }

    // Sort the prefix sums in ascending order
    sort(P.begin(), P.end());

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        // The smallest prefix sum gets the largest permutation value (n)
        // The largest prefix sum gets the smallest permutation value (1)
        p[P[i].second] = n - i;
    }

    // Output the resulting permutation
    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}