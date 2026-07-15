#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n, 0));
  
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            cin >> v[i][j];
        }
    }
    ll sum = 0;

    for(auto row : v){
        vector<int> copy = row;
        sort(copy.begin(), copy.end());
        
        for(size_t i  = 0; i < copy.size(); i++){
            ll contribution = (ll)(copy[i] * i) - (ll)(copy[i] * (n - 1 - (i + 1) + 1));
            sum += contribution;
        }
    }

    cout << sum << endl;

    //transpose the matrix and then desc sort each row -> keep adding the difference of a[i] - a[j] O(m * nlogn)
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}