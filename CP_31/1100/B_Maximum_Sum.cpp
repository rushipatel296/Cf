#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(all(arr));

    vector<ll> prefix_sum(n);
    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    // vector<ll> answers(k + 1);
    ll ans = -INF;

    for(int i = 0; i <= k; i++){
        //say we do i operations of type 1 and (k - i) operations of type 2
        int start = i * 2;
        int end = (n - 1) - (k - i);
        ll sum = prefix_sum[end] - (start - 1 >= 0 ? prefix_sum[start - 1] : 0);
        ans = max(ans, sum);
    }
    cout << ans << endl;

    // int i = 0, j = n - 1;
    // int ops = 0;
    // while(ops < k && i <= j){
    //     ops++;
    //     cout << "OP : " << ops << endl;
    //     ll option1 = arr[i] + (i + 1 < n ? arr[i + 1] : 0);
    //     ll option2 = arr[j];
    //     cout << "Sum of min 2 : " << option1 << " , Maximum : " << option2 << endl;
    //     if(option1 <= option2){
    //         i = i + 2;
    //         cout << "Incrementing lower bound to index : " << i << endl;
    //         sum -= option1;
    //     }else{
    //         j--;
    //         cout << "Decrementing upper bound to index : " << j << endl;
    //         sum -= option2;
    //     }
    //     cout << "Cur Sum of the array : " << sum << endl;
        
    // }
    // cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}