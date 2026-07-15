#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void solve() {
    // Write your solution here
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    int min_diff = INT_MAX;
    for(int i = 1; i < n; i++){
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
    }
    int ans = 0;

    while(min_diff >= 0){
        min_diff = min_diff - 2;
        ans++;
    }
    cout << ans << endl;
    
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}