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

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++) cin >> arr[i];

//     vector<int> freq(m + 1, 0);

//     for(int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//     }
//     vector<int> pref(m + 1, 0); //count of lengths <= i
//     for(int i = 1; i <= m; i++){
//         pref[i] = pref[i - 1] + freq[i];
//     }


//     vector<ll> ans(m + 1, 0);
//     // vector<int> output;

//     for(int h = 1; h <= m; h++){
//         ll cur = 0;
//         for(int k = 1; (h * k) <= m; k++){// for a height h and cuts = k
//             cur += (pref[m] - pref[(k * h) - 1]);

//             ll tot_for_k = cur;
//             if((k + 1) * h <= m){
//                 tot_for_k += freq[(k + 1) * h];
//             }
//             ans[k] = max(ans[k], tot_for_k);
//         }
//     }

//     for(int i = 2; i <= m; i++){
//         ans[i] = max(ans[i - 1], ans[i]);
//     }

//     for(int i = 1; i <= m; i++){
//         cout << ans[i] << " ";
//     }
//     debug(ans);
//     cout << endl;

// }
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> freq(m + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    vector<int> pref(m + 1, 0); 
    for(int i = 1; i <= m; i++){
        pref[i] = pref[i - 1] + freq[i];
    }

    vector<ll> ans(m + 1, 0);

    for(int h = 1; h <= m; h++){
        
        vector<ll> pieces_for_k(19, 0);
        
        for(int C = 1; C * h <= m; C++){
            int L = C * h;
            int R = min((C + 1) * h - 1, m);
            ll count_C = pref[R] - pref[L - 1]; // Number of carrots yielding exactly C pieces
            
            if(count_C == 0) continue;
            
            for(int k = 1; k <= 18 && k <= m; k++){
                ll pieces = 0;
                if(C <= (1LL << k)){
                    pieces = C;
                } else {
                    pieces = (1LL << k) - 1;
                }
                
                pieces_for_k[k] += pieces * count_C;
            }
        }
        
        for(int k = 1; k <= 18 && k <= m; k++){
            ans[k] = max(ans[k], pieces_for_k[k]);
        }
    }

    for(int i = 2; i <= m; i++){
        ans[i] = max(ans[i - 1], ans[i]);
    }

    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
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