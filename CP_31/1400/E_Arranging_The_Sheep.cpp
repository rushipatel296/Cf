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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sheep_count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '*') sheep_count++;
    }

    int median_sheep_pos = (sheep_count + 1) / 2;
    int median_index = -1;
    int cur_cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            cur_cnt++;
        }
        if(cur_cnt == median_sheep_pos){
            median_index = i;
            break;
        }
    }
    debug(median_sheep_pos)
    debug(median_index)
    int dot_cnt = 0;
    ll ans = 0;
    for(int i = median_index + 1; i < n; i++){
        if(s[i] == '.'){
            dot_cnt++;
        }else{
            ans += dot_cnt;
        }
    }
    dot_cnt = 0;
    for(int i = median_index - 1; i >= 0; i--){
        if(s[i] == '.'){
            dot_cnt++;
        }else{
            ans += dot_cnt;
        }
    }
    cout << ans << endl;

    
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