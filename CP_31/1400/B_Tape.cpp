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

// int helper(int index, int cur_k, vector<int>& arr){
//     if(index < 0) return 0;

//     if(cur_k == 1){
//         return arr[index] - arr[0] + 1;
//     }
//     if(cur_k <= 0){
//         return INT_MAX;
//     }

//     int opt1 = INT_MAX, opt2 = INT_MAX;

//     //use a new piece of tape for current index
//     opt1 = helper(index - 1, cur_k - 1, arr) + 1;

//     //not use a new piece of tape, instead extend the tape piece from the previous index
//     opt2 = helper(index - 1, cur_k, arr) + (arr[index] - arr[index - 1]);
//     // cout << "For index = " << index << " ans = " << min(opt1, opt2) << endl;
//     return min(opt1, opt2);
// }

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // vector<vector<int>> dp(n, vector<int> (k + 1, 1e9));

    // for(int i = 0; i < n; i++){
    //     dp[i][1] = arr[i] - arr[0] + 1;
    // }

    // for(int index = 1; index < n; index++){
    //     for(int cur_k = 2; cur_k <= k; cur_k++){
    //         int opt1 = dp[index - 1][cur_k - 1] + 1;
    //         int opt2 = dp[index - 1][cur_k] + (arr[index] - arr[index - 1]);
    //         dp[index][cur_k] = min(opt1, opt2);
    //     }
    // }


    // cout <<  dp[n - 1][k] << endl;

    // N - K pieces would be left after using K pieces of tape 

    vector<int> diff(n - 1);
    for(int i = 0; i < n - 1; i++){
        diff[i] = arr[i + 1] - arr[i] - 1;
    }

    sort(all(diff));


    ll ans = n;
    for(int i = 0; i < n - k; i++){
        ans += diff[i];
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
    // cin >> t;
    while(t--)
        solve();
}