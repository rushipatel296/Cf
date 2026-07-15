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

    vector<pair<ll, ll>> v(n);

    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;

        v[i] = {ele, i};
    }

    sort(all(v));

    vector<ll> pre(n);
    pre[0] = v[0].first;
    for(int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + v[i].first;
    }
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int j = i;
        int found = i;
        while(j < n){
            pair<ll, ll> temp = {pre[j] + 1, INT_MIN};
            ll idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
            idx--;
            if(idx == j){
                break;
            }
            found += idx - j;
            j = idx;    
        }

        ans[v[i].second] = found;
    }

    for(auto ele : ans){
        cout << ele << " ";
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