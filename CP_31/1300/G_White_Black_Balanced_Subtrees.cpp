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

//<b, w>
pair<int, int> dfs(vector<vector<int>>& children, string color, int node, int& count){

    int b = 0;
    int w = 0;

    for(auto child : children[node]){
        auto [child_b, child_w] = dfs(children, color, child, count);
        b += child_b;
        w += child_w;
    }

    int cur_col = (color[node - 1] == 'B' ? 0 : 1);
    if(cur_col == 0){
        b++;
    }else{
        w++;
    }

    if(b == w){
        count++;
    }
    return {b, w};
}

void solve(){
    int n;
    cin >> n;

    vector<int> parent(n + 1);

    for(int i = 2; i <= n; i++) cin >> parent[i]; // 1 based indexing

    string color;
    cin >> color; // color follows a 0 based index;

    vector<vector<int>> children(n + 1);
    for(int c = 2; c <= n; c++){
        children[parent[c]].push_back(c);
    }
    debug(children);

    int count = 0;
    dfs(children, color, 1, count);
    // debug(count);
    cout<< count << endl;

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