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
    ll x, k;
    cin >> k >> x;

    ll i = 0;
    // there are 2 possibilities 1 <= i <= k or k < i <= 2k - 1 

    
    if (x >= k * k) {
        cout << 2 * k - 1 << endl;
        return;
    }
    //case 1
    if(x <= (k * (k + 1) / 2)){
        ll lo = 1, hi = k;
        ll target = x;

        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;

            if((mid * (mid + 1)) / 2 < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
                i = mid;
            }
        }
    }else{
        ll remaining_sum  = x - ((k * (k + 1)) / 2);
        ll lo = 1;
        ll hi = k - 1;
        ll messages_in_second_half = 0;

        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            
            ll sum = mid * (2 * k - 1 - mid) / 2;

            if(sum >= remaining_sum){
                messages_in_second_half = mid; 
                hi = mid - 1;                  
            } else {
                lo = mid + 1;                  
            }
        }
        
        i = k + messages_in_second_half;

    }

    cout << i << endl;
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