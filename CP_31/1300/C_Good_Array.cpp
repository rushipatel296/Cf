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

    vector<ll> prefix_sum(n, 0);
    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> temp(arr);
    sort(all(temp));
    prefix_sum[0] = temp[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + temp[i];
    }
    debug(temp);
    debug(prefix_sum);
    int largest = temp[n - 1];

    vector<int> ans;
    for(int index = 0; index < n; index++){
        // cout << "index : " << index << endl;
        if(arr[index] != largest){
            // cout << "Not the largest element (" << arr[index] << ")" << endl;
            if(prefix_sum[n - 2] - arr[index] == largest) {
                
                ans.push_back(index + 1);
            }
        }else{
            if(n > 2 && prefix_sum[n - 3] == temp[n - 2]){
                // cout << "Case : largest element (" << arr[index] << ")" << endl;

                ans.push_back(index + 1);
            }else if(n <= 2 && temp[0] == 0){
                ans.push_back(index + 1);
            }
        }
    }
    cout << ans.size() << endl;
    if(ans.size() > 0){
        for(int ele : ans){
            cout << ele << " ";
        }
        cout << endl;
    }
    
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