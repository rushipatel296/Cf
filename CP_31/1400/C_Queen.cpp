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

void dfs(int node, vector<vector<int>>& children_of, vector<int>& c, vector<int> &ans){
    bool harami_child = true;
    bool harami_node = (c[node] == true ? true : false);

    for(auto child : children_of[node]){
        if(c[child] == false){
            harami_child = false;
        }
        dfs(child, children_of, c, ans);
    }

    if(harami_child && harami_node){
        ans.push_back(node);
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    int root = -1;   
    vector<int> c(n);
    vector<vector<int>> children_of(n);
    for(int i = 0; i < n; i++){
        int parent;
        cin >> parent;
        cin >> c[i];
        if(parent != -1){
            children_of[parent - 1].push_back(i);    
        }else{
            root = i;
        }
        
    }

    debug(children_of);
    vector<int> ans;

    dfs(root, children_of, c, ans);
    if(ans.size() == 0){
        cout << -1 << endl;
    }else{
        sort(all(ans));

        for(auto ele : ans){
            cout << ele + 1 << " ";
        }
        cout << endl;
    }

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