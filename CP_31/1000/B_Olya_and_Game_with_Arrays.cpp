#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    // there is a list of n arrays
    vector<vector<ll>> lst (n);

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;  
        vector<ll> a(m);
        for(int j = 0; j < m; j++){
            cin >> a[j];
        }
        sort(all(a));
        lst[i] = a;
    }

    ll ans = -INF;

    ll mini = INF;
    ll second_sum = 0;

    for(int i = 0; i < n; i++){
        mini = min(mini, lst[i][0]);
        second_sum += lst[i][1];
    }

    for(int i = 0; i < n; i++){
        ll candidate_ans = mini + (second_sum - lst[i][1]);
        ans = max(candidate_ans, ans);
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