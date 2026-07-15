#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    vector<ll> x(q);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < q; i++){
        cin >> x[i];
    }

    ll prev = 31;

    for(ll i = 0; i < q; i++){
        if(x[i] >= prev) continue;
        ll ele = pow(2, x[i]);
        for(ll j = 0; j < n; j++){
            if(a[j] % ele == 0){
                a[j] += ele / 2;
            }
        }

        prev = min(x[i], prev);
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}