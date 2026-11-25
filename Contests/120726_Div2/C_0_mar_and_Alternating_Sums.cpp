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

ll modpower(ll n, ll e){
    ll res = 1;
    n %= MOD; 
    while(e > 0){
        if((e & 1) == 1){
            res = (res * n) % MOD;
        }

        n = (n * n) % MOD;
        e = e / 2;
    }

    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;

    auto end = unique(arr.begin(), arr.end());
    arr.erase(end, arr.end());

    ll ans = 0;
    ll W = 1;

    int m1 = freq[-1];
    int unique_n = arr.size();
    int K = 0;

    for(int i = 0; i < unique_n; i++){
        if(arr[i] != -1){
            W = (W * modpower(2, freq[arr[i]] - 1)) % MOD;

            if(i + 1 < unique_n && arr[i + 1] == arr[i] + 1){
                K++;
            }
        }
    }

    ll c_even = (m1 > 0) ? modpower(2, m1 - 1) : 1;
    ll c_odd = (m1 > 0) ? modpower(2, m1 - 1) : 0;

    ll even_ans = (c_even * W) % MOD;
    ll odd_ans = (((c_odd * W) % MOD) * K) % MOD;
    
    ans = (even_ans + odd_ans) % MOD;
    cout << ans << "\n";
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