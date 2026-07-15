#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    } //inputs

    sort(arr.begin(), arr.end());
    //sliding window

    long long max_window = 1;
    long long start = 0;
    long long end = 0;
    for(int i = 1; i < n; i++){
        int dif = arr[i] - arr[i - 1];
        // cout << "index : " << i << " diff : " << dif <<endl;
        if(dif <= k){
            end++;
            // cout << "dif <= k -> end++. End : " << end << endl;
        }else{
            start = i;
            end = i;
            // cout << "dif > k -> new window. Start & End : " << i << endl;
        }
        // cout << "cur window : " << end - start + 1 << endl;
        max_window = max(max_window, end - start + 1);
    }

    cout << n - max_window << endl;

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