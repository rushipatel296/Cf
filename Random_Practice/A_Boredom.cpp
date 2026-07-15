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



ll helper(int num, map<int, int> freq){
    if(num <= 0) return 0;

    //there are two options for each number 
    ll option1 = -INF, option2 = -INF;

    option1 = helper(num - 1, freq);
    option2 = helper(num - 2, freq) + (freq[num] * num);

    return max(option1, option2);
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    ll sum = 0;
    map<int, int> freq;

    int maxi = INT_MIN;
    for(auto ele : arr){
        sum += ele;
        freq[ele]++;
        maxi = max(maxi, ele);
    }
    // cout << helper(maxi, freq) << endl;

    vector<ll> dp(maxi + 1, 0);

    if (maxi >= 1) {
        dp[1] = freq[1] * 1;
    }

    for(int num = 2; num <= maxi; num++){
        ll option1 = dp[num - 1]; 
        ll option2 = dp[num - 2] + (freq[num] * (ll)num); 

        dp[num] = max(option1, option2);
    }

    cout << dp[maxi] << "\n";

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