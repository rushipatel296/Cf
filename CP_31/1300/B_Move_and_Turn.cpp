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

set<pair<int, int>> helper(int n){
    if(n == 0){
        set<pair<int, int>> temp;
        temp.insert({0, 0});
        return temp;
    }

    set<pair<int, int>> prevPoints = helper(n - 1);
    set<pair<int, int>> ans;
    for(auto[x, y] : prevPoints){
        if(x == y){
            ans.insert({x + 1, y});
            ans.insert({x - 1, y});
            ans.insert({x, y + 1});
            ans.insert({x, y - 1});
        }else if(abs(x) % 2 == 0 && (n - 1) % 2 == 1){
            // last move was a horizontal move if prev total moves were odd and horizontal moves were even
            ans.insert({x, y + 1});
            ans.insert({x, y - 1});
        }else{
            //last move was vertical
            ans.insert({x + 1, y});
            ans.insert({x - 1, y});
        }
    }
    debug(n);
    debug(ans);
    return ans;
}


void solve(){
    int n;
    cin >> n;

    set<pair<int, int>> stt = helper(n);
    cout << stt.size() << endl;
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