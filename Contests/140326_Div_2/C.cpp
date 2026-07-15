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

    vector<pair<int, int>> arr(n);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    //(c_i, p_i)

    vector<double> dp(n + 1);
    dp[n] = 0.0;
    for(int i = n - 1; i >= 0; i--){
        double option2 = dp[i + 1];
        double option1 = arr[i].first + (1.0 - arr[i].second / 100.0) * option2;
        dp[i] = max(option1, option2);
    }
    double ans = dp[0];
    // cout << ans << endl;
    cout << fixed << setprecision(10) << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}