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



void solve(){
    int a, b, k;
    cin >> a >> b >> k;

    vector<pair<int, int>> e(k);
    vector<int> b_count(a, 0);
    vector<int> g_count(b, 0);

    vector<int> t1(k), t2(k);
    for(int i = 0; i < k; i++){
        cin >> t1[i];
    }
    for(int i = 0; i < k; i++){
        cin >> t2[i];
    }
    

    for(int i = 0; i < k; i++){
        int b = t1[i], g = t2[i];
        b--;
        g--;
        e[i] = {b, g};
        b_count[b]++;
        g_count[g]++;
    }
    debug(e);
    debug(b_count);
    debug(g_count);

    ll count = 0;
    for(auto [b, g] : e){
        //edge between b and g
        // cout << "Edge : " <<  b << " " << g << endl;
        ll temp = b_count[b] + g_count[g] - 1;
        // cout << "Remaining possibilities for current edge : " << k - temp << endl;
        count += (k - temp);
    }
    count = count / 2;
    debug(count);
    cout << count << endl;

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