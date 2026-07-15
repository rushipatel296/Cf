#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll B_normal = (k % n == 0) ? n : k % n;
    if(n % 2 == 1){
        ll a = ((n - 2) + 1) / 2;
        ll num_increments = (k - 1) / a;
        B_normal += num_increments;
        B_normal = (B_normal % n == 0) ? n : B_normal % n; 
    }

    cout << B_normal << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}