#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    // Write your solution here
    int n;
    cin >> n;

    vector<int> b;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        b.pb(ele);
    }

    vector<int> ans;

    for(int i = 0; i < b.size(); i++){
        if(i == 0){
            ans.push_back(b[0]);
        }else{
            if(b[i - 1] <= b[i]){
                ans.pb(b[i]);
            }else{
                ans.pb(b[i]);
                ans.pb(b[i]);
            }
        }
    }

    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}