#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    // Write your solution here
    int n, x;
    cin >> n >> x;
    int prev = 0;
    int cur = 0;
    int max_dif = 0;
    for(int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        if(prev == 0){
            max_dif = cur - prev;
        }else{
            max_dif = max(max_dif, cur - prev);
        }
        prev = cur;
    }
    max_dif = max(max_dif, 2 * (x - prev));
    cout << max_dif << endl;
    return ;

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