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

    int removals = 0;
    for(int i = 1; i < n; i++){
        removals += ((arr[i] == arr[i - 1]) ? 1 : 0);
    }

    bool adj_consec_colors = false;

    bool consec_1 = false;
    bool consec_2 = false;
    int col1 = -1;
    int col2 = -1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            if(col1 == -1 || col1 == arr[i]){
                consec_1 = true;
                col1 = arr[i];
            }else{
                col2 = arr[i];
            }
        }else{
            if(consec_1){
                if(i + 1 < n && (arr[i + 1] == arr[i])){
                    consec_2 = true;
                    col2 = arr[i];
                    adj_consec_colors = true;
                    break;
                }else{
                    consec_1 = false;
                    col1 = -1;
                }
            }
        }
    }

    if(adj_consec_colors){
        removals = removals - 2;
    }else{
        //check if swappable pair exists

        int start = 0;
        int end = 0;
        bool swappable_pair = false;
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i - 1]){
                end++;
            }else{
                if(end - start + 1 >= 2){
                    if((end + 2 < n && arr[end + 2] != arr[end]) || (end + 2 == n)) {
                        swappable_pair = true;
                    }
                    if((start - 2 >= 0 && arr[start - 2] != arr[start]) || (start - 1 == 0)) {
                        swappable_pair = true;
                    }
                    if(swappable_pair) break;
                }

                start = i;
                end = i;
            }
        }
        if(end - start + 1 >= 2){
            if((end + 2 < n && arr[end + 2] != arr[end]) || (end + 2 == n)) {
                swappable_pair = true;
            }
            if((start - 2 >= 0 && arr[start - 2] != arr[start]) || (start - 1 == 0)) {
                swappable_pair = true;
            }
        }
        debug(swappable_pair)
        if(swappable_pair){
            removals--;
        }
    }

    cout << n - removals << endl;
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