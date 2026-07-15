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

void solve() {
    int n;
    cin >> n;

    // 1-based indexing for universities requires size n + 1
    vector<vector<long long>> v(n + 1);
    vector<int> u(n);
    vector<long long> s(n);

    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Group students by university
    for (int i = 0; i < n; i++) {
        v[u[i]].push_back(s[i]);
    }

    // Sort skills descending and compute prefix sums in-place
    for (int i = 1; i <= n; i++) {
        if (v[i].empty()) continue;
        
        sort(v[i].rbegin(), v[i].rend());
        
        // v[i][j] becomes the sum of the first j + 1 strongest students
        for (size_t j = 1; j < v[i].size(); j++) {
            v[i][j] += v[i][j - 1];
        }
    }

    // ans[k] will store the total strength for team size k
    vector<long long> ans(n + 1, 0);

    // Process each university independently
    for (int i = 1; i <= n; i++) {
        int m = v[i].size();
        if (m == 0) continue;

        // A university of size m only contributes to team sizes k from 1 to m
        for (int k = 1; k <= m; k++) {
            int usable_students = m - (m % k);
            // Add the sum of the top 'usable_students' to the answer for size k
            // Index is usable_students - 1 because vector is 0-indexed
            ans[k] += v[i][usable_students - 1];
        }
    }

    // Output results for k = 1 to n
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << (k == n ? "" : " ");
    }
    cout << "\n";
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