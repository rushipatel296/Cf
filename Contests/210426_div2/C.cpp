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


// int helper(int index, const string& s1, const string& s2) {
//     int n = s1.size();
//     if (index >= n) return 0;

//     int vert_cost = (s1[index] != s2[index] ? 1 : 0);
//     int total_vert = vert_cost + helper(index + 1, s1, s2);

//     int total_horiz = 1e9; 
//     if (index + 1 < n) {
//         int horiz_cost = (s1[index] != s1[index + 1] ? 1 : 0) + (s2[index] != s2[index + 1] ? 1 : 0);
//         total_horiz = horiz_cost + helper(index + 2, s1, s2);
//     }

//     return min(total_vert, total_horiz); 
// }

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    
    vector<int> dp(n + 1, 0);

    for(int index = n; index >= 0; index--){
        int n = s1.size();
        if (index >= n) {
            dp[index] = 0;
            continue;
        }
    
        int vert_cost = (s1[index] != s2[index] ? 1 : 0);
        int total_vert = vert_cost + dp[index + 1];
    
        int total_horiz = 1e9; 
        if (index + 1 < n) {
            int horiz_cost = (s1[index] != s1[index + 1] ? 1 : 0) + (s2[index] != s2[index + 1] ? 1 : 0);
            total_horiz = horiz_cost + dp[index + 2];
        }
    
        dp[index] =  min(total_vert, total_horiz); 
    }
    // ops = helper(0, s1, s2);
    cout << dp[0] << endl;
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