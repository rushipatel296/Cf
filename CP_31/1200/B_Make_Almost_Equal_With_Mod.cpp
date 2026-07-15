#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll ans = 0;
    for(int i = 1; i <= 60; i++){
        ll div = 1LL << i;

        set<ll> eles;
        for(ll i = 0; i < n; i++){
            eles.insert((arr[i] % div));
        } 

        if(eles.size() == 2){
            ans = div;
            break;
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