#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, k, x;

    cin >> n >> k >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    sort(all(arr));
    vector<ll> k_count;
    
    for(ll i = 1; i < n; i++){

        if(arr[i] - arr[i - 1] > x){
            ll diff = arr[i] - arr[i - 1];
            ll k_req = (diff - 1) / x;
            k_count.push_back(k_req);
        }
        
    }

    sort(all(k_count));

    ll ans = k_count.size() + 1;
    size_t i = 0;
    while(k > 0 && i < k_count.size()){
        if(k_count[i] <= k){
            k = k - k_count[i];
            ans--;
        }else{
            break;
        }
        i++;
    }


    cout << ans << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}