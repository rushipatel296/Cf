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

    set<int> nums = {4, 8, 15, 16, 23, 42};
    vector<int> arr = {4, 8, 15, 16, 23, 42};
    map<int, pair<int, int>> mp;

    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            mp[arr[i] * arr[j]] = {arr[i], arr[j]};
        }
    }

    vector<int> ans(6);
    int n;

    cout << "? 1 6" << endl;
    cin >> n;
    int a = mp[n].first;
    int b = mp[n].second;

    //q2
    cout << "? 1 2" << endl;
    cin >> n;
    int c = mp[n].first;
    int d = mp[n].second;

    if(a == c){
        ans[0] = a;
        ans[5] = b;
        ans[1] = d;
    }else if(a == d){
        ans[0] = a;
        ans[5] = b;
        ans[1] = c;
    }else if(b == c){
        ans[0] = b;
        ans[5] = a;
        ans[1] = d;
    }else{ //b == d
        ans[0] = b;
        ans[5] = a;
        ans[1] = c;
    }
    nums.erase(ans[0]);
    nums.erase(ans[5]);
    nums.erase(ans[1]);
    // debug(ans);
    // debug(nums);
    //q3
    cout << "? 3 3" << endl;
    // fflush(stdout);
    cin >> n;

    n = round(sqrt(float(n)));
    ans[2] = (int)n;
    nums.erase(ans[2]);
    // debug(ans);
    // debug(nums);
    //q4
    cout << "? 5 5" << endl;
    // fflush(stdout);
    cin >> n;

    n = round(sqrt(float(n)));
    ans[4] = (int)n;
    nums.erase(ans[4]);
    // debug(ans);
    // debug(nums);

    ans[3] = *nums.begin();
    // debug(ans);
    cout << "! ";
    for(auto ele : ans){
        cout << ele << " ";
    }
    cout << endl;
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}