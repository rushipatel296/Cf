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
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++){
        mp[arr[i]].push_back(i);
    }
    debug(mp);

    int candidate_1 = -1, candidate_2 = -1;
    int l1 = 0, l2 = 0; 
    bool possible = true;

    for(auto [ele, indices] : mp){
        int count = indices.size();
        int maxi_len = 1;
        int cur = 1;
        for(int j = 1; j < count; j++){
            if(indices[j] == indices[j - 1] + 1){
                cur++;
            }else{
                maxi_len = max(maxi_len, cur);
                cur = 1;
            }
        }
        maxi_len = max(maxi_len, cur);

        if(maxi_len != count){
            if(candidate_1 == -1){
                candidate_1 = ele;
                l1 = maxi_len;
            }else if(candidate_2 == -1){
                candidate_2 = ele;
                l2 = maxi_len;
            }else{
                possible = false;
                break;
            }
        }
    }

    debug(candidate_1)
    debug(l1)
    debug(candidate_2)
    debug(l2)
    debug((int)mp.size())
    if(possible){
        if(candidate_1 != -1 && candidate_2 != -1 && (l1 >= ((int)mp[candidate_1].size() + 1) / 2) && (l2 >= ((int)mp[candidate_2].size() + 1) / 2)){
            cout << "YES" << endl;
        }else if((candidate_1 != -1 && candidate_2 == -1 && mp.size() == 2) || (candidate_1 == -1 && candidate_2 == -1)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
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