#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // float opt1 = (2 * b - c) / (1.0 * a);
    long long opt1 = (2 * b - c);
    if(opt1 % a == 0 && opt1 > 0){
        cout << "YES" << endl;
        return;
    }
    // float opt2 = (c + a) / (2.0 * b);
    long long opt2 = c + a;
    if(opt2 % (2 * b) == 0 && opt2 > 0){
        cout << "YES" << endl;
        return;
    }
    // float opt3 = (2 * b - a) / (1.0 * c);
    long long opt3 = (2 * b ) - a;
    if(opt3 % c == 0 && opt3 > 0){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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