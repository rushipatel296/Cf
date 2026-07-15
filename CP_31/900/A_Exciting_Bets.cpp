#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll a, b;
    cin >> a >> b;
    
    ll max = abs(a - b);
    ll moves = min(a % max, max - (a % max));
    if(max == 0) {
        moves = 0;
    }

    
    cout << max << " " << moves << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}