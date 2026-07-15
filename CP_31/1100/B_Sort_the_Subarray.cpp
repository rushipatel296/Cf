#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int L = 0, R = n - 1;

    // 1. Find the first mismatch from the left
    while (L < n && a[L] == b[L]) {
        L++;
    }

    // 2. Find the first mismatch from the right
    while (R >= 0 && a[R] == b[R]) {
        R--;
    }

    // 3. Expand L to the left if it maintains the sorted order in 'b'
    while (L > 0 && b[L - 1] <= b[L]) {
        L--;
    }

    // 4. Expand R to the right if it maintains the sorted order in 'b'
    while (R < n - 1 && b[R] <= b[R + 1]) {
        R++;
    }

    // Output 1-based indices
    cout << L + 1 << " " << R + 1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}