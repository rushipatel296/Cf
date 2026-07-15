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

    vector<int> six_f ,two_f, three_f, rem;

    for(int i = 0; i < n; i++){
        if(arr[i] % 6 == 0){
            six_f.push_back(arr[i]);
        }else if(arr[i] % 2 == 0){
            two_f.push_back(arr[i]);
        }else if(arr[i] % 3 == 0){
            three_f.push_back(arr[i]);
        }else{
            rem.push_back(arr[i]);
        }
    }
    debug(six_f)
    debug(two_f)
    debug(three_f)
    debug(rem)
    if(two_f.size() < three_f.size()){
        //first multiples of 6 then 2 and the other side would be 3

        int i = 0;
        for(auto ele : six_f){
            arr[i] = ele;
            i++;
        }
        for(auto ele : two_f){
            arr[i] = ele;
            i++;
        }
        for(auto ele : rem){
            arr[i] = ele;
            i++;
        }
        for(auto ele : three_f){
            arr[i] = ele;
            i++;
        }
    }else{
        int i = 0;
        for(auto ele : six_f){
            arr[i] = ele;
            i++;
        }
        for(auto ele : three_f){
            arr[i] = ele;
            i++;
        }
        for(auto ele : rem){
            arr[i] = ele;
            i++;
        }
        for(auto ele : two_f){
            arr[i] = ele;
            i++;
        }
    }

    for(auto ele : arr){
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