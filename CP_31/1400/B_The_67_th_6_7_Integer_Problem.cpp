#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        vector<long long> a(7);
        long long total_sum = 0;
        long long max_val = -100; // Initialize lower than the minimum constraint (-67)
        
        for (int i = 0; i < 7; ++i) {
            cin >> a[i];
            total_sum += a[i];
            if (a[i] > max_val) {
                max_val = a[i];
            }
        }
        
        long long ans = 2 * max_val - total_sum;
        cout << ans << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}