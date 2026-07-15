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

// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     int q;
//     cin >> q;

//     int p = 0;
//     int m = 0;

//     for(char c : s){
//         if(c == '+'){
//             p++;
//         }else{
//             m++;
//         }
//     }


//     while(q--){
//         ll n1, n2;
//         cin >> n1 >> n2;
//         ll a = max(n1, n2);
//         ll b = min(n1, n2);
//         bool possible = false;

//         ll num = 1LL * b * (m - p);
//         ll den =  (a - b);
//         if(a == b){
//             possible = (p == m); 
//         }else{
//             if(num % den == 0){
//                 ll d = num / den;
//                 if(d <= p && d >= -m){
//                     possible = true;
//                 }
//             }
//         }
//         if(possible){
//             cout << "YES" << endl;
//         }else{
//             cout << "NO" << endl;
//         }
//     }
// }
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;

    int p = 0, m = 0;
    for(char c : s) {
        if(c == '+') p++;
        else m++;
    }

    while(q--){
        ll n1, n2;
        cin >> n1 >> n2;
        ll a = max(n1, n2);
        ll b = min(n1, n2);

        // Edge case: division by zero preventer
        if (a == b) {
            if (p == m) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        // Your exact logic
        int pairs = min(p, m);
        int excess = max(p, m);
        
        // The maximum score the pairs can cancel out
        ll range = 1LL * pairs * (a - b);
        
        // The minimum score the excess symbols will generate (x = 0)
        ll min_excess_score = 1LL * excess * b;

        bool possible = false;
        
        // Condition 1 (Your Binary Search Bounds): Can the pairs reach this score?
        if (min_excess_score <= range) {
            // Condition 2 (LDE / GCD): Is the gap perfectly divisible by the step size?
            if (min_excess_score % (a - b) == 0) {
                possible = true;
            }
        }

        if(possible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
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