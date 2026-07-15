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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;

        map<int, int> f;
        
        for(int i = 0; i < n; i++){
            int ele;
            cin >> ele;
            f[ele]++;
        }   
        
        ll sum = 0;
        // debug(f);

        vector<pair<int, int>> v;
        for(auto [ele, freq] : f){
            v.push_back({freq, ele});
        }

        sort(v.rbegin(), v.rend());
        debug(v);
        int counter = -1;
        for(int i = 0; i < (int)v.size(); i++){
            int freq = v[i].first;
            int ele = v[i].second;
            debug(freq)
            debug(ele)
            if(counter == -1){
                counter = freq;
            }
            if(freq >= counter){
                sum += counter;
            }else{
                //freq < counter
                counter = freq;
                sum += counter;
            }
            counter--;
            if(counter == 0) break;
        }

        cout << sum << endl;
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