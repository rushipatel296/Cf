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

    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> zero_count;
    // int trailing_zeros = 0;
    int digit_count = 0;

    for(auto ele : arr){
        int trailing_zeros = 0;
        while(ele % 10 == 0){
            trailing_zeros++;
            ele = ele / 10;
        }
        if(trailing_zeros != 0){
            zero_count.push_back(trailing_zeros);
        }
        while(ele > 0){
            digit_count++;
            ele = ele / 10;
        }
    }

    sort(zero_count.rbegin(), zero_count.rend());
    debug(zero_count)
    debug(digit_count)
    for(size_t i = 0; i < zero_count.size(); i++){
        if(i % 2 == 1){
            digit_count += zero_count[i];
        }
    }
    debug(digit_count)
    debug(m)
    if(digit_count >= m + 1){
        cout << "Sasha" << endl;
    }else{
        cout << "Anna" << endl;
    }
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