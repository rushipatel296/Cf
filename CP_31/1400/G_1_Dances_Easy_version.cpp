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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);

    a[0] = 1;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int largest_b = b[n - 1];
    int j = n - 1;
    while(j >= 0 && a[j] >= largest_b){
        j--;
    }

    int ops = (n - 1) - j;

    a.erase(a.begin() + j + 1, a.end());
    debug(a);

    b.erase(b.begin(), b.begin() + ops);
    debug(b)

    map<int, int> cum_freq;

    int new_n = b.size();
    for(int i = new_n - 1; i >= 0; i--){
        cum_freq[b[i]] = new_n - i;
    }

    debug(cum_freq)

    //cum_Freq tracks the number of elements present in b which are greated than or equal to the key

    vector<int> temp(new_n, 0);

    for(int i = new_n - 1; i >= 0; i--){
        int ele = a[i];
        auto it = lower_bound(b.begin(), b.end(), ele + 1);
        if(it != b.end()){
            temp[i] = cum_freq[*it];
        }
    }
    debug(temp);
    int assigned = 0;
    for(int i = new_n - 1; i >= 0; i--){
        if(temp[i] - assigned > 0){
            assigned++;
        }else{
            ops++;
        }
    }
    debug(ops);
    cout << ops << endl;
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