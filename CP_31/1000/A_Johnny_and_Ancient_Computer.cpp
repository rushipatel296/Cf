#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll a, b;
    cin >> a >> b;

    ll larger = (a > b ? a : b);
    ll smaller = (a <= b ? a : b);
    // cout << "Debug : " << "Larger : " << larger << " , Smaller : " << smaller << endl; 
    int ops = 0;
    while(smaller < larger){
        smaller = smaller << 1;
        // cout << "Debug : " << "Larger : " << larger << " , Smaller : " << smaller << endl; 
        ops++;
    }

    if(smaller != larger){
        cout << -1 << endl;
    }else{
        int ans = ops / 3;
        if(ops % 3 > 0){
            ans++;
        }
        cout << ans << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}