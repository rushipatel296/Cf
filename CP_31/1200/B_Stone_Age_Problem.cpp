#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll total_sum = 0;
    vector<int> time_updated(n, 0);

    for(int i = 0; i < n; i++){
        total_sum += arr[i];
    }
    
    int localTime = 0;
    int last_global_update_time = 0;
    int global_element = 0;

    while(q--){
        localTime++;
        int type;
        cin >> type;
        if(type == 1){
            int idx, num;
            cin >> idx >> num;
            idx--;
            if(time_updated[idx] < last_global_update_time){
                total_sum = total_sum - global_element + num;
            }else{
                total_sum = total_sum - arr[idx] + num;
            }
            arr[idx] = num;
            time_updated[idx] = localTime;
        }else{
            int ele;
            cin >> ele;
            // arr = vector<int>(n, ele);
            total_sum = 1LL * n * ele;
            last_global_update_time = localTime;
            global_element = ele;
        }
        cout << total_sum << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}