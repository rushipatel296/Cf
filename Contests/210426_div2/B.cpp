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
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> freq;
    int cur = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            cur++;
        }else{
            if(cur != 1){
                freq[cur]++;
            }
            cur = 1;
        }
    }
    if(cur != 1){
        freq[cur]++;
    }

    debug(freq);
    bool possible = true;
    int remaining_ops = 1;
    for(auto [len, f] : freq){
        if(len >= 4){
            possible = false;
            break;
        }else if(len == 3){
            if(f > 1 || remaining_ops == 0){
                possible = false;
                break;
            }
            remaining_ops--;
            
        }else if(len == 2){
            if(f > 2 || remaining_ops == 0){
                possible = false;
                break;
            }
            remaining_ops--;
        }
    }

    if(possible){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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