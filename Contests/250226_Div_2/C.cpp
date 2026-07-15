#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The greedy checker function
bool check(long long limit, long long s, long long m) {
    long long rem = s;
    
    // 60 is enough since 2^60 > 10^18 (the max value of s and m)
    for (int i = 60; i >= 0; i--) {
        // If the i-th bit is set in m
        if ((m >> i) & 1) {
            // Take as much as we can: either our limit 'n', or what fits in 'rem'
            // 'rem >> i' is a fast way of doing 'rem / (1LL << i)'
            long long take = min(limit, rem >> i); 
            rem -= take * (1LL << i);
        }
    }
    
    // If the remaining sum is exactly 0, this 'limit' (array length) works
    return rem == 0; 
}

void solve() {
    long long s, m;
    cin >> s >> m;
    
    // If it's impossible to form the sum even if we use up to 's' elements,
    // then it's mathematically impossible (because the smallest possible valid element is 1)
    if (!check(s, s, m)) {
        cout << -1 << "\n";
        return;
    }
    
    // Binary Search for the minimum array length
    long long low = 1, high = s;
    long long ans = -1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (check(mid, s, m)) {
            ans = mid;      // mid is a valid length, record it
            high = mid - 1; // Try to find a smaller valid length
        } else {
            low = mid + 1;  // mid is too small, we need a larger limit
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}