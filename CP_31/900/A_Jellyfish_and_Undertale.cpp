#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    long long a, b, n;
    cin >> a >> b >> n;
    vector<long long> tools(n);
    for(int i = 0; i < n; i++){
        cin >> tools[i];
    }

    long long time = b;

    for(auto ele : tools){
        time += min(ele, a - 1);
    }

    cout << time << endl;


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