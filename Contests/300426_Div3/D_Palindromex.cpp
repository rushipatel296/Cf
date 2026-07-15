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
    vector<int> arr(2 * n);
    for(int i = 0; i < (2 * n); i++) cin >> arr[i];

    //case 1 one of the zeros is the centre, locate both zeros first
    int i1 = -1, i2 = -1;

    for(int i = 0; i < (2 * n); i++){
        if(arr[i] == 0){
            if(i1 == -1){
                i1 = i;
            }else{
                i2 = i;
                break;
            }
        }
    }

    //case1 check if either of the zeros are a centre

    int i = i1, j = i1;
    int ans = 1;
    
    while(i >= 0 && j < (2*n) && arr[i] == arr[j]){ 
        i--;
        j++;
    }
    
    vector<bool> seen(n, false);
    for(int start = i + 1; start <= j - 1; start++){ 
        seen[arr[start]] = true;
    }
    
    int cur_mex = 0;
    while(cur_mex < n && seen[cur_mex]){
        cur_mex++;
    }
    ans = max(ans, cur_mex);

    seen = vector<bool> (n, false);

    i = i2, j = i2;
    while(i >= 0 && j < (2*n) && arr[i] == arr[j]){
        i--;
        j++;
    }
    
    for(int start = i + 1; start <= j - 1; start++){
        seen[arr[start]] = true;
    }
    
    cur_mex = 0;
    while(cur_mex < n && seen[cur_mex]){
        cur_mex++;
    }
    ans = max(ans, cur_mex);

    seen = vector<bool> (n, false);

    //case 2 : both zeros are part of the sequence

    i = i1; j = i2;
    while(i <= j && arr[i] == arr[j]){
        i++;
        j--;
    }
    
    if(i > j){
        //expand the other way as well since the in between elements are palindromic

        i = i1; j = i2;
        while(i >= 0 && j < (2 * n) && arr[i] == arr[j]){
            i--;
            j++;
        }
        
        for(int start = i + 1; start <= j - 1; start++){
            seen[arr[start]] = true;
        }
        
        cur_mex = 0;
        while(cur_mex < n && seen[cur_mex]){
            cur_mex++;
        }
        ans = max(ans, cur_mex);
    }

    cout << ans << endl;
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