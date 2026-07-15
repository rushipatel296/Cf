#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, m, i, j;
    cin >> n >> m >> i >> j;

    // ll x1, y1, x2, y2;

    // if(i > (n / 2)){
    //     x1 = 1;
    // }else{
    //     x1 = n;
    // }

    // if(j > (m / 2)){
    //     y1 = 1;
    // }else{
    //     y1 = m;
    // }

    // if(abs(x1 - i) > abs(y1 - j)){ // more vertical displ
    //     x2 = x1;
    //     y2 = (y1 == 1 ? m : 1);
    // }else{
    //     x2 = (x1 == 1 ? n : 1);
    //     y2 = y1;
    // }
    cout <<  1 << " " << 1 << " " << n << " " << m << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}