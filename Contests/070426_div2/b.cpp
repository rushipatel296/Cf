#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int pivot; 
    cin >> pivot;
    pivot--; // Convert to 0-based index

    // 1. Count transitions on the left side of the pivot
    int cL = 0;
    for (int i = pivot - 1; i >= 0; i--) {
        if (arr[i] != arr[i + 1]) cL++;
    }

    // 2. Count transitions on the right side of the pivot
    int cR = 0;
    for (int i = pivot; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) cR++;
    }

    // 3. We need at least the maximum of both sides
    int ans = max(cL, cR);
    
    // 4. The number of operations must be even to restore the pivot
    if (ans % 2 != 0) ans++;

    cout << ans << "\n";
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