#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll n2 = 0;

    for(ll i = 0; i < n; i++){
        n2 += ceil(arr[i] / (1.0 * x));
    }

    for(ll i = 1; i < n; i++){
        if(arr[i] % x != 0 || arr[i - 1] % x != 0){
            arr[i] = arr[i] + arr[i - 1];
            arr[i - 1] = 0;
            // i--;
        }
    }

    // cout << "Debug arr for min : " << endl;
    // for(ll i = 0; i < n; i++){
    //     cout << arr[i] << " " ;
    // }

    ll n1 = 0;
    for(ll i = 0; i < n; i++){
        n1 += ceil(arr[i] / (1.0 * x));
    }

    cout << n1 << " " << n2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while(t--)
        solve();
}