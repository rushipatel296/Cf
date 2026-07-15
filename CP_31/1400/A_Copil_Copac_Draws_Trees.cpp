#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9 + 7;

// --- DEBUG TEMPLATE BEGIN ---
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// --- DEBUG TEMPLATE END ---


 

// void dfs(vector<vector<int>>& adj, vector<int>& parent, int node){
//     for(auto child : adj[node]){
//         if(child != parent[node]){
//             parent[child] = node;
//             dfs(adj, parent, child);
//         }
//     }
// }

void dfs(vector<vector<int>>& adj, map<pair<int, int>, int>& idx, vector<int>& dp, int node, int parent){
    for(auto neighbor : adj[node]){
        if(neighbor != parent){
            if(idx[{node, neighbor}] > idx[{node, parent}]){
                dp[neighbor] = dp[node];
            }else{
                dp[neighbor] = dp[node] + 1;
            }
            dfs(adj, idx, dp, neighbor, node);
        }
        
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    map<pair<int, int>, int> idx;  
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    idx[{1, -1}] = -1;
    idx[{-1, 1}] = -1;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        idx[{u, v}] = i;
        idx[{v, u}] = i;
    }
    // debug(adj);

    dfs(adj, idx, dp, 1, -1);

    cout << *max_element(dp.begin(), dp.end()) << endl;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}