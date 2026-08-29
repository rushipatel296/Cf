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

// pair<ll, int> helper(int index, vector<int>& arr, int a, int b){ // returns {cost, prev_capital(num)}
//     if(index >= arr.size()) return {0, 0};
//     auto [cost, prev_cap] = helper(index - 1, arr, a, b);

//     //there are two options - either switch captial to prev index or keep it at the prev_cap

//     ll opt1 = 1LL * b * (arr[index] - prev_cap);
//     ll opt2 = 0;
//     if(index > 0){
//         opt2 = (1LL * a * (arr[index - 1] - prev_cap)) + (1LL * b * (arr[index] - arr[index - 1]));
//     }
//     else{
//         opt2 = 1LL * b * arr[index];
//     }
//     // if(a > b){
//     //     cost += 1LL * b * (arr[index] - prev_cap);
//     // }else{
//     //     if(index > 0){
//     //         cost += (1LL * a * (arr[index - 1] - prev_cap)) + (1LL * b * (arr[index] - arr[index - 1]));
//     //         prev_cap = arr[index - 1];
//     //     }else{
//     //         cost = 1LL * b * arr[index];
//     //     }
//     // }
//     // debug(index);
//     // debug(cost);
//     // debug(prev_cap);
//     if(opt1 < opt2){
//         return {cost + opt1, prev_cap};
//     }else{
//         return {cost + opt2, arr[index - 1]};
//     }

    

//     return {cost, prev_cap};
// }

void solve(){
    int n;
    ll a, b;
    cin >> n >> a >> b;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll cap = 0;
    ll cost = 0;
    for(int i = 0; i < n; i++){
        // if cost to move capital is less than future savings -> it is beneficial to move the capital
        cost += 1LL * b * (arr[i] - cap);

        if((1LL * a) <= (1LL * (n - i - 1) * b)){
            cost += 1LL * a * (arr[i] - cap);
            cap = arr[i];
        }
    }

    cout << cost << endl;


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