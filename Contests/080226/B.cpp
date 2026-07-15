#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;
// void print(vector<long long>& arr){
//     for(long long i = 0; i < arr.size(); i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void solve() {
//     long long n, x, y;
//     cin >> n >> x >> y;

//     vector<long long> arr(n);

//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     sort(arr.begin(), arr.end());

//     long long left = 0;
//     long long largest = 0;
//     long long smallest = n - 1;
//     long long remaining = n - 1;

//     while(remaining > 0){
//         long long L = arr[largest];
//         long long S = arr[smallest];
//         arr[smallest] = S + (L / x) * y;
//         arr[largest] = (L % x);
//         remaining--;
//         swap(arr[largest], arr[smallest]);

//         smallest--;
//         cout << "Arr : ";
//          print(arr); 
//     }
//     cout << "Ans : " <<  arr[largest] << endl;
// }
void solve() {
    long long n, x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);

    long long totalTransfers = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        totalTransfers += a[i] / x;
    }

    long long ans = 0;

    for(int i = 0; i < n; i++){
        long long transfers = totalTransfers - (a[i] / x);
        long long cur = a[i] + transfers * y;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
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