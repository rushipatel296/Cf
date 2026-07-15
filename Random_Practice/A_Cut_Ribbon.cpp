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

int helper(int len, int a, int b, int c){
    if(len == 0) return 0;
    if(len < a && len < b && len < c){
        return -1;
    }

    int option1 = INT_MIN, option2 = INT_MIN, option3 = INT_MIN;
    if(len >= a){
        option1 = helper(len - a, a, b, c);
        if(option1 != -1){
            option1++;
        }
    }

    if(len >= b){
        option2 = helper(len - b, a, b, c);
        if(option2 != -1){
            option2++;
        }
    }

    if(len >= c){
        option3 = helper(len - c, a, b, c);
        if(option3 != -1){
            option3++;
        }
    }

    if(option1 == -1 && option2 == -1 && option3 == -1) return -1;
    // cout << "for n = " << len << " , ans : " << max(option1, max(option2, option3)) << endl;
    return max(option1, max(option2, option3));

}

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, 0);

    for(int len = 1; len <= n; len++){
        int ans ;
        if(len < a && len < b && len < c){
            ans = -1;
        }else{
            int option1 = INT_MIN, option2 = INT_MIN, option3 = INT_MIN;
            if(len >= a){
                option1 = dp[len - a];
                if(option1 != -1){
                    option1++;
                }
            }

            if(len >= b){
                option2 = dp[len - b];
                if(option2 != -1){
                    option2++;
                }
            }

            if(len >= c){
                option3 = dp[len - c];
                if(option3 != -1){
                    option3++;
                }
            }

            if(option1 == -1 && option2 == -1 && option3 == -1) ans = -1;
            // cout << "for n = " << len << " , ans : " << max(option1, max(option2, option3)) << endl;
            ans =  max(option1, max(option2, option3));
        }
        dp[len] = ans;
    }
    debug(dp);
    cout << dp[n] << endl;

    // cout << helper(n, a, b, c) << endl;

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