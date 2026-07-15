#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(all(arr));
    
    vector<ll> prefix(n);
    prefix[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    ll total = 0;

    for(int i = 0; i < n; i++){
        int num_shops = i + 1;
        if(prefix[i] > x){
            continue;
        }
        int num_days = (x - prefix[i]) / num_shops;
        total += num_days + 1;

    }
    cout << total << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}