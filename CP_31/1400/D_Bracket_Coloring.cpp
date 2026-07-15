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
    int n ;
    cin >> n;
    string s;
    cin >> s;

    bool found_reg = false;

    int open = 0;
    int close = 0;
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            open++;
        }else{
            close++;
        }
    }

    if(open != close){
        cout << -1 << endl;
        return;
    }

    open = 0, close = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            if(open >= 0){
                ans[i] = 1;
                found_reg = true;
            }
            open++;
        }else if(s[i] == ')'){
            if(open > 0){
                ans[i] = 1;
            }
            open--;
        }
        debug(open);
    }
    debug(ans);
    int color ;
    if(!found_reg){
        color = 1;
    }else{
        color = 2;
    }

    bool found_diff = false;

    for(int i = 0; i < n; i++){
        if(ans[i] == -1){
            found_diff = true;
            ans[i] = color;
        }
    }

    if(found_reg && found_diff){
        cout << 2 << endl;
    }else{
        cout << 1 << endl;
    }
    for(int ele : ans){
        cout << ele << " ";
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