#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, c;
    cin >> n >> c;

    vector<ll> arr(n);
    // ll a = 0;
    // ll b = 0;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        // a += arr[i];
        // b += arr[i] * arr[i];
    }

    ll lo = 1;
    ll hi = 1e9;
    ll ans = 0;

    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        ll ar = 0;
        bool overflowed = false;
        for(ll i = 0; i < n; i++){
            ll side = arr[i] + 2 * mid;

            if(side >= 2e9){
                overflowed = true;
                break;
            }
            ar += (side) * (side);
            if(ar > c){
                overflowed = true;
                break;
            }
        }
        if(!overflowed && ar == c){
            ans = mid;
            break;
        } else if(!overflowed && ar < c){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
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