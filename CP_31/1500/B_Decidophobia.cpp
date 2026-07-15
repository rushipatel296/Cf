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
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0;

    ll sum_weights = 0;
    //calculate for the first index i = 0;

    for(int i = 1; i <= d; i++){ // CW
        sum_weights += arr[i];
    }

    for(int i = n - 1; i >= n - d; i--){ //ACW
        sum_weights += arr[i];
    }

    if((2LL * d * arr[0]) - sum_weights > 0){
        ans += (2LL * d * arr[0]) - sum_weights;
    }


    for(int i = 1; i < n; i++){
        ll cur = 0;
        int prev_idx = i - 1;
        int last_acw_index = prev_idx - d;
        if(last_acw_index < 0){
            last_acw_index += n;
        }

        sum_weights -= arr[last_acw_index];
        sum_weights += arr[prev_idx];
        
        int last_cw_index = i + d;
        if(last_cw_index >= n){
            last_cw_index -= n;
        }

        sum_weights -= arr[i];
        sum_weights += arr[last_cw_index];

        if((2LL * d * arr[i]) - sum_weights > 0){
            ans += (2LL * d * arr[i]) - sum_weights;
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