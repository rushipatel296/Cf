#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    ll s1 = 0, s2 = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s1 += arr[i];
    }
    s2 += arr[n - 1];
    s1 -= arr[n - 1];
    int i = n - 2;
    ll ans = gcd(s1, s2);
    while(i > 0){
        s1 -= arr[i];
        s2 += arr[i];
        ans = max(ans, gcd(s1, s2));
        i--;
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