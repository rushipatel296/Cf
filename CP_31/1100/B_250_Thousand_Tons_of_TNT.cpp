#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

vector<int> findFactors(int n){
    if(n == 1){
        return {1};
    }
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i * i <= n; i++){ //O(sqrt(n))
        if(n % i == 0){
            ans.push_back(i);
            int f2 = n / i;
            if(f2 != i){
                ans.push_back(f2);
            }
        }
    }

    ans.push_back(n);
    // cout << "Debug : " << endl;
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return ans;
}

void solve(){
    int n;
    cin >> n;

    vector<int> factors = findFactors(n);

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<ll> prefix_sum(n); 

    prefix_sum[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    // cout << "Debug Prefix Sum array :" << endl;
    // for(int i = 0; i < n; i++){
    //     cout << prefix_sum[i] << " ";
    // }
    // cout << endl;
    
    ll ans = 0;
    
    for(int size : factors){
        ll maxi = -INF;
        ll mini = INF; 
        // cout << "Each truck contains " << size << " boxes" << endl;
        int truck_count  = n / size;
        int start = -1;
        int end = -1;
        int i = 1;
        while(truck_count > 0){
            start = end + 1;
            end = start + size - 1;
            // cout << "Start : " << start << " End : " << end << endl;
            ll window_sum = prefix_sum[end] - ((start - 1 >= 0) ? prefix_sum[start - 1] : 0);
            // cout << "Truck " << i++ << " weighs " << window_sum << endl;
            maxi = max(maxi, window_sum);
            mini = min(mini, window_sum);

            ans = max(ans, maxi - mini);
            truck_count--;
        }
        // maxi = INT_MIN;
        // mini = INT_MAX;
        // cout << "Ans so far : " << ans << endl;
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}