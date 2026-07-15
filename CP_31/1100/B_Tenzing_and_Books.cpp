#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, target;
    cin >> n >> target;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }

    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }

    ll cur = 0;

    for(ll i = 0; i < n; i++){
        if((target | a[i]) == target){
            cur = cur | a[i];
        }else{
            break;
        }
    }

    for(ll i = 0; i < n; i++){
        if((target | b[i]) == target){
            cur = cur | b[i];
        }else{
            break;
        }
    }
    
    for(ll i = 0; i < n; i++){
        if((target | c[i]) == target){
            cur = cur | c[i];
        }else{
            break;
        }
    }

    if(cur == target){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}