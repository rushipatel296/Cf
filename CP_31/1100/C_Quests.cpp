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

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    ll ans = INT_MIN;
    vector<ll> prefix_sum(n);

    prefix_sum[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = a[i] + prefix_sum[i - 1];
    }
    int highest_so_far = INT_MIN;

    
    for(int i = 0; i < n; i++){
        if(i + 1 <= k){
            ll cur = prefix_sum[i];
            int rem = k - (i + 1);

            highest_so_far = max(highest_so_far, b[i]);
            cur += 1LL * rem * highest_so_far;
            ans = max(ans, cur);
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