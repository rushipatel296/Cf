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

bool check(int start, int end, const vector<vector<int>>& pre, int k){
    int cur = 0;
    for(int bit = 0; bit < 32; bit++){
        if(pre[end][bit] - ((start > 0) ? pre[start - 1][bit] : 0) == end - start + 1){
            cur += (1LL << bit);
        }
    }

    if(cur >= k){
        return true;
    }else{
        return false;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    

    for(int i = 0; i < n; i++) cin >> arr[i];
    debug(arr)
    vector<vector<int>> pre(n, vector<int>(32, 0)); //n x 32

    for(int i = 0; i < n; i++){
        if (i > 0) {
            pre[i] = pre[i - 1]; 
        }
        
        for(int j = 0; j < 32; j++){
            if(arr[i] & (1LL << j)){ 
                pre[i][j]++; 
            }
        }
    }
    debug(pre)

    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        l--;
        int start_l = l;
        if(arr[l] < k){
            cout << -1 << " ";
        }else{
            int r = n - 1;
            while(l < r){
                int mid = l + (r - l + 1) / 2; // calculate the higher median when l = mid
    
                if(check(start_l, mid, pre, k)){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            cout << l + 1 << " ";
        }
        
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