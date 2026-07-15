#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    long long n, k;
    cin >> n >> k;

    if(n % 2 == 0){
        cout << "YES" << endl;
        return;
    }else{  //n is odd
        // cout << n <<" is odd" << endl;
        if(k % 2 == 0){
            cout << "NO" << endl;
            return;
        }else{
            //n is odd and k is also odd
            if(n >= k){
                cout << "YES" << endl;
                return;
            }else{
                cout << "NO" << endl;
                return;
            }
        }
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