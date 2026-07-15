#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

ll countPaths(set<pair<int, int>>& visited, int i, int j, int n, int m, int mod){
    //3 options to increase count
    cout << "Cur cell : (" << i << ", " << j << ")" << endl;
    if(visited.find({i, j}) != visited.end()){
        cout << "Already visited "<< i << ", " << j << endl;
        return 0;
    }
    if(i >= n || i < 0 || j >= m || j < 0) return 0;
    if(i == n - 1 && j == n - 1) return 1;

    visited.insert({i, j});
    ll count = 0;//stop
    if(i + 1 < n){ // down
        cout << "calling (" << i + 1 << ", " << j << ")" << endl;
        count += 1 + countPaths(visited, i + 1, j , n , m , mod) % mod;
    }
    if(j + 1 < m){//right
        cout << "calling (" << i << ", " << j + 1 << ")" << endl;
        count += 1 + countPaths(visited, i, j + 1, n, m, mod) % mod;
        
    }
    if(j - 1 >= 0){ // left
        cout << "calling (" << i << ", " << j - 1<< ")" << endl;
        count += 1 + countPaths(visited, i, j - 1, n, m, mod) % mod;
    }
    visited.erase({i, j});
    cout << "Num paths from (" << i << ", " << j  << ") = " <<  count<< endl;
    return count;
}

void solve(){
    int n, m, mod;
    cin >> n >> m >> mod;
    set<pair<int, int>> visited;

    cout << countPaths(visited, 0, 0, n, m, mod) << endl;
    // vector<vector<int>> mat(n, vector<int>(m, 0));
    // vector<vector<int>> visited(n, vector<int>(m, false));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}