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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s; 

    vector<int> prefix(n, 0);

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + ((s[i] == s[i - 1]) ? 1 : 0);
    }


    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;

        int errors = prefix[r] - prefix[l];

        int count = (errors + 1) / 2;
        if(count <= k){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

// void solve() {
//     int n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;
//     vector<int> pref(n, 0);
//     for (int i = 0; i < n - 1; ++i) {
//         pref[i + 1] = pref[i] + (s[i] == s[i + 1] ? 1 : 0);
//     }
//     for (int i = 0; i < q; ++i) {
//         int l, r, k;
//         cin >> l >> r >> k;
//         if (l == r) {
//             cout << "YES\n";
//             continue;
//         }
//         int c = pref[r - 1] - pref[l - 1];
//         int needed = (c + 1) / 2;
//         if (needed <= k) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }


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