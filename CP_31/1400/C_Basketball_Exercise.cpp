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

// ll helper(vector<ll>& a, vector<ll>& b, int index, bool pick_r1){
//     int n = a.size();
//     if(index >= n) return 0;
//     ll ans = 0;

//     if(index == 0){
//         ll option1 = a[0] + helper(a, b, index + 1, false);
//         ll option2 = b[0] + helper(a, b, index + 1, true);
//         ans = max(option1, option2);
//     }else{
//         ll opt1, opt2;
//         if(pick_r1){
//             opt1 = a[index] + helper(a, b, index + 1, !pick_r1);
//             opt2 = helper(a, b, index + 1, pick_r1);
//         }else{
//             opt1 = b[index] + helper(a, b, index + 1, !pick_r1);
//             opt2 = helper(a, b, index + 1, pick_r1);
//         }

//         ans = max(opt1, opt2);
//     }

//     return ans;
// }

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];


    vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));

    for(int index = n - 1; index >= 0; index--){

        dp[index][1] = max(a[index] + dp[index + 1][0], dp[index + 1][1]); //pick_r1
        dp[index][0] = max(b[index] + dp[index + 1][1], dp[index + 1][0]); // dont pick_r1

    }
    debug(dp);
    cout << max(dp[0][0], dp[0][1]) << endl;
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