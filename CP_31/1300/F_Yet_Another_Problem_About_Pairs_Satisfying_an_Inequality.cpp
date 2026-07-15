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

    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++){
        int ele;
        cin >> ele;
        if(ele >= i){
            continue;
        }

        v.push_back({i, ele});
    }

    int size = v.size();    
    vector<int> candidates(size, 0);

    for(int i = size - 1; i >= 0; i--){
        

        auto [index, element]  = v[i];
        //find next pair in the vector where element >= index + 1
        pair<int, int> temp = {INT_MIN, index + 1};

        auto j = lower_bound(v.begin() + i, v.end(), temp) - v.begin();

        if(j != size){
            //found
            candidates[i] = 1 + candidates[j];
            //we need one more check
            int temp_idx = v[j].first;
            int temp_ele = v[j].second;

            pair<int, int> temp2 = {INT_MIN, temp_idx};

            auto k = lower_bound(v.begin() + j, v.end(), temp2);

            if(k != v.end()){
                candidates[i]++;
            }
        }

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