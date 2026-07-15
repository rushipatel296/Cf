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

    ll ans = INF;

    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(all(b));
    sort(all(a));
    int j = n;

    for(int i = n - 1; i >= 0; i--){
        while(j - 1 >= 0 && a[j - 1] > b[i]){
            j--;
        }

        int options = (n - 1 - j + 1);
        int done = (n - 1) - i ;
        int ways = options - done;

        if(ans == INF){
            ans = 1LL * ways;
        }else{
            ans = (1LL * ans * ways) % MOD;
        }
    }

    cout << ans % MOD << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}