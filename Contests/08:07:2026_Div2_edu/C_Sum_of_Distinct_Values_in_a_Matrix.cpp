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

int n, m;
vector<int> LA, LB, LAB;
map<tuple<int, int, int, int, int>, long long> memo;

long long solve(int i, int j, int k, int r, int c) {
    if (r + c + k >= n + m) return 0;
    auto state = make_tuple(i, j, k, r, c);
    if (memo.count(state)) return memo[state];

    long long ans = 0;
    if (i < LA.size() && r < n && (r + c + k < n + m - 1)) {
        ans = max(ans, (long long)LA[i] + solve(i + 1, j, k, r + 1, c));
    }
    if (j < LB.size() && c < m && (r + c + k < n + m - 1)) {
        ans = max(ans, (long long)LB[j] + solve(i, j + 1, k, r, c + 1));
    }
    if (k < LAB.size() && (r < n || c < m) && (r + c + k < n + m)) {
        ans = max(ans, (long long)LAB[k] + solve(i, j, k + 1, min(n, r + 1), min(m, c + 1)));
    }

    return memo[state] = ans;
}

void solve() {
    int x, y;
    if (!(cin >> n >> m >> x >> y)) return;
    vector<int> a(x), b(y);
    set<int> set_a, set_b;
    for (int i = 0; i < x; i++) {
        cin >> a[i];
        set_a.insert(a[i]);
    }
    for (int i = 0; i < y; i++) {
        cin >> b[i];
        set_b.insert(b[i]);
    }

    LA.clear(); LB.clear(); LAB.clear();
    memo.clear();

    for (int v : a) {
        if (!set_b.count(v)) LA.push_back(v);
        else LAB.push_back(v);
    }
    for (int v : b) {
        if (!set_a.count(v)) LB.push_back(v);
    }

    sort(LA.rbegin(), LA.rend());
    sort(LB.rbegin(), LB.rend());
    sort(LAB.rbegin(), LAB.rend());

    cout << solve(0, 0, 0, 0, 0) << "\n";
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