#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    long long n;
    cin >> n;

    if(n % 2 == 1 || n < 4){
        cout << -1 << endl;
    }else{
        long long maxi = (n / 4);
        long long mini = ((n + 5)/ 6);
        cout << mini << " " << maxi << endl;
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