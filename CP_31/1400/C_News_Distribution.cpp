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

void dfs(vector<vector<int>>& edges, int vertex, vector<bool>& visited, vector<int>& component){
    visited[vertex] = true;
    component.push_back(vertex);
    for(auto neighbor : edges[vertex]){
        if(!visited[neighbor]){
            dfs(edges, neighbor, visited, component);
        }
    }
    return;
}

void solve(){
    int n, m;
    cin >> n >> m;  

    vector<vector<int>> edges(n);

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        vector<int> group;
        while(k--){
            int ele;
            cin >> ele;
            ele--; 
            group.push_back(ele);
        }


        for(int j = 1; j < (int)group.size(); j++){
            int cur = group[j];
            int prev = group[j - 1];

            edges[cur].push_back(prev);
            edges[prev].push_back(cur);
        }
    }
    debug(edges);

    vector<int> ans(n);
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> component;
            
            // Run DFS to find everyone connected to user 'i'
            dfs(edges, i, visited, component);
            
            // Everyone in this component has the same answer (the size of the component)
            int size_of_group = component.size();
            for(int user : component){
                ans[user] = size_of_group;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}