#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<int>> coprimes(1001);

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> idx(1001, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        idx[a[i]] = i + 1;
    }
    int ans = -1;
    for(int i = 1; i <= 1000; i++){
        if(idx[i] != -1){
            for(int j = 0; j < coprimes[i].size(); j++){
                if(idx[coprimes[i][j]] != -1){
                    ans = max(ans, idx[i] + idx[coprimes[i][j]]);
                }
            }
        }
    }
    cout << ans << endl;

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(gcd(i, j) == 1){
                coprimes[i].push_back(j);
            }
        }
    }

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}