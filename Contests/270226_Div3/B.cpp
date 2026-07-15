#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if (is_sorted(all(arr))) {
        cout << n << "\n";
    } else {
        cout << 1 << "\n";
    }
    // int peaks = 0;

    // for(int i = 1; i < n - 1; i++){
    //     if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]){
    //         peaks++;
    //     }
    // }

    // cout << (peaks == 0 ? n : 1) << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}