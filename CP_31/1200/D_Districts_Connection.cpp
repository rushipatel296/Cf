#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void dfs(int node, vector<int>& arr, vector<bool>& visited, set<pair<int, int>>& edges){
    visited[node] = true;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] != arr[node] && !visited[i]){
            edges.insert({node, i});
            dfs(i, arr, visited, edges);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<bool> visited(n, false);
    set<pair<int, int>> edges;
    dfs(0, arr, visited, edges);

    if((int)edges.size() == n - 1){
        cout << "YES" << endl;
        for(auto [i, j] : edges){
            cout << i + 1 << " " << j + 1 << endl;
        }
    }else{
        cout << "NO" << endl;
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