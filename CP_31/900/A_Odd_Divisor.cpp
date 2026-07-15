#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n;
    cin >> n;

    if(n % 2 == 1 && n > 1){
        cout << "YES" << endl;
    }else{
        if(n == 1){
            cout << "NO" << endl;
        }
        //even n
        while(n % 2 == 0){
            n = n / 2;
        }

        if(n == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}