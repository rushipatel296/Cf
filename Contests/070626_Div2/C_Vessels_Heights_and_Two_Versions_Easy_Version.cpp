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
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++){
        vector<int> L(n, 0);
        vector<int> R(n, 0);

        int count = 0;
        int index = (i + 1) % n;

        while(count < n - 1){
            int prev;
            if(index == 0){
                prev = n - 1;
            }else{
                prev = index - 1;
            }
            L[index] = max(arr[prev], L[prev]);
            index = (index + 1) % n;
            count++;
        }

        index = (i - 1);
        if(i == 0){
            index = n - 1;
        }
        count = 0;
        while(count < n - 1){
            int prev;
            if(index == n - 1){
                prev = 0;
            }else{
                prev = index + 1;
            }
            R[index] = max(arr[index], R[prev]);
            index = index - 1;
            if(index == -1){
                index = n - 1;
            }
            count++;
        }
        ll ans = 0;
        for(int j = 0; j < n; j++){
            ans += min(L[j], R[j]);
        }
        cout << ans << " ";
    }   
    cout << endl;
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