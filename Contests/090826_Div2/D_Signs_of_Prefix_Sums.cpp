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
    string s;
    cin >> s;

    vector<int> arr(n);
    int sum_so_far = 0;

    for(int i = 0; i < n; i++){
        if(i == 0){
            if(s[i] == '0') {
                cout << -1 << endl;
                return;
            }else if(s[i] == '+'){
                arr[i] = 1;
                sum_so_far++;
            }else{
                arr[i] = -1;
                sum_so_far--;
            }
        }else{
            if(s[i] == '0'){
                if(s[i - 1] == '0'){
                    cout << -1 << endl;
                    return;
                }else if(s[i - 1] == '+'){
                    arr[i] = -(sum_so_far);
                    sum_so_far = 0;
                }else{
                    arr[i] = abs(sum_so_far);
                    sum_so_far = 0;
                }
            }

            else if(s[i] == '+'){
                if(s[i - 1] == '+'){
                    if(sum_so_far > 1){
                        arr[i] = -1;
                        sum_so_far--; //still remains positive
                    }else{
                        arr[i] = 1;
                        sum_so_far += 1;
                    }
                }else if(s[i - 1] == '-'){ //"-+"
                    arr[i] = abs(sum_so_far) + 1;
                    sum_so_far = 1;
                }else{
                    //0+
                    arr[i] = 1;
                    sum_so_far = 1;
                }
            }else{
                if(s[i - 1] == '-'){
                    if(sum_so_far < -1){
                        arr[i] = 1;
                        sum_so_far += 1;
                    }else{
                        arr[i] = -1;
                        sum_so_far--;
                    }
                }else if(s[i - 1] == '+'){
                    arr[i] = -(sum_so_far + 1);
                    sum_so_far = -1;
                }else{
                    arr[i] = -1;
                    sum_so_far = -1;
                }
            }
        }
    }
    int ans = 0;
    for(auto ele : arr){
        ans = max(abs(ele), ans);
    }
    cout << ans << endl;


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