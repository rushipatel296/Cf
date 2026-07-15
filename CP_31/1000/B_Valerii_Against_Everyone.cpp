#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // arr[i] = (1 << arr[i]);
    }

    // unordered_set<ll, pair<int, int>> mpp;
    // unordered_map<int, ll> r_idx_of;
    // //stores (sum , (l, r))
    // vector<ll> prefix(n);

    // prefix[0] = arr[0];

    // for(int i = 1; i < n; i++){
    //     prefix[i] = prefix[i - 1] + arr[i];
    // }
    // bool ans = false;
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         ll subarr_sum = prefix[j] - ((i - 1 >= 0) ? prefix[i - 1] : 0);
    //         if(r_idx_of.count(subarr_sum) > 0){
    //             int end_idx = r_idx_of[subarr_sum];
    //             if(end_idx < i){
    //                 ans = true;
    //                 break;
    //             }
    //         }
            
    //         r_idx_of[subarr_sum] = j;
    //     }
    // }

    // if(ans){
    //     cout << "YES" << endl;
    // }else{
    //     cout << "NO" << endl;
    // }

    sort(arr.begin(), arr.end());
    bool ans = false;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            ans = true;
            break;
        }
    }

    cout << (ans == true ? "YES" : "NO") << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}