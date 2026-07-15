#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    vector<pair<ll, ll>> points(n);

    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }


    ll option1 = abs(points[a].first - points[b].first) + abs(points[a].second - points[b].second);

    //find point in first k closest to a and b

    pair<ll, ll> closest_a;
    pair<ll, ll> closest_b;
    ll D1 = INF, D2 = INF;
    for(ll i = 0; i < k; i++){
        ll cur1 = abs(points[i].first - points[a].first) + abs(points[i].second - points[a].second);
        if(cur1 < D1){
            D1 = cur1;
            closest_a = points[i];
        }
        ll cur2 = abs(points[i].first - points[b].first) + abs(points[i].second - points[b].second);
        if(cur2 < D2){
            D2 = cur2;
            closest_b = points[i];
        }
    }

    ll option2 = D1 + D2;
    cout  << min(option1, option2) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}