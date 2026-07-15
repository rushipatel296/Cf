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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;


    stack<int> st;
    vector<int> closing_idx, opening_idx;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            if(!st.empty()){
                int open = st.top();
                st.pop();

                opening_idx.push_back(open);
                closing_idx.push_back(i);
            }
        }
    }

    sort(all(closing_idx));
    sort(opening_idx.rbegin(),opening_idx.rend());
    debug(opening_idx);
    debug(closing_idx);

    int num_pairs = closing_idx.size();
    int max_deletions = min(k, num_pairs);
    
    int min_cost = 1e9; 
    vector<int> best_ans(n, 0); 

    for(int x = 0; x <= max_deletions; x++){
        int y = max_deletions - x;
        vector<int> current_del(n, 0);

        for(int i = 0; i < x; i++){
            current_del[closing_idx[i]] = 1;
        }
        for(int i = 0; i < y; i++){
            current_del[opening_idx[i]] = 1;
        }

        int current_cost = 0;
        int open_count = 0;
        
        for(int i = 0; i < n; i++){
            if(current_del[i] == 1) continue;

            if(s[i] == '('){
                open_count++;
            } else if(s[i] == ')' && open_count > 0){
                open_count--;
                current_cost += 2; 
            }
        }

        if(current_cost < min_cost){
            min_cost = current_cost;
            best_ans = current_del;
        }
    }

    for(int i = 0; i < n; i++){
        cout << best_ans[i];
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