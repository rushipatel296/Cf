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
    vector<pair<int, int>> v;
    while(n--){
        int k;
        cin >> k;
        vector<int> temp(k);

        for(int i = 0; i < k; i++){
            cin >> temp[i];
        }
        int min_req = INT_MIN; 
        for(int i = 0; i < k; i++){
            min_req = max(min_req, temp[i] + 1 - i);
        }

        debug(min_req);

        v.push_back({min_req, k});
    }
    sort(v.begin(), v.end());
    debug(v);
    long long ans = 0;
    long long cur_pow = 0;
    
    for (size_t i = 0; i < v.size(); i++) {
        if(cur_pow < v[i].first){
            ll deficit = v[i].first - cur_pow;

            cur_pow += deficit;
            ans += deficit;

        }
        cur_pow += v[i].second;

    }
    debug(ans);
    debug(cur_pow);

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