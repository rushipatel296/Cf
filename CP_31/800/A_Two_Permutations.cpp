#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, lcp, lcs;
    cin >> n >> lcp >> lcs;
    
    if(n - lcs - lcp >= 2){
        cout << "YES" << endl;
    }
    else if(n == lcs && n == lcp){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}