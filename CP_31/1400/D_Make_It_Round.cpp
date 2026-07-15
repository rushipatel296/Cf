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
    ll n, m;
    cin >> n >> m;

    int pow_of_2_in_n = 0, pow_of_5_in_n = 0;

    ll copy = n;
    while(copy % 2 == 0){
        copy = copy / 2;
        pow_of_2_in_n++;
    }
    while(copy % 5 == 0){
        copy = copy / 5;
        pow_of_5_in_n++;
    }

    int excess_2 = 0, excess_5 = 0;
    if(pow_of_2_in_n > pow_of_5_in_n){
        excess_2 = pow_of_2_in_n - pow_of_5_in_n;
    }else{
        excess_5 = pow_of_5_in_n - pow_of_2_in_n;
    }

    //first try to fill the excess void
    // debug(excess_2)
    // debug(excess_5);
    ll prod = 1; 
        
    while(excess_2 && (prod * 5) <= m){
        excess_2--;
        prod = prod * 5;
    }
    while(excess_5 && (prod * 2) <= m){
        excess_5--;
        prod = prod * 2;
    }

    //now try to increase zero count 
    while(prod * 10 <= m){
        prod = prod * 10;
    }

    //now search for the first multiple of prod s.t multiple * prod <= m

    ll lo = 1; 
    ll hi = m;
    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(mid * prod <= m){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }

    // debug(lo);

    prod = prod * lo;

    cout << n * prod << endl;
    debug(n * prod) ;


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