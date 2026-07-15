#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

bool isFair(ll n){
    ll copy = n;
    while(copy != 0){
        int digit = copy % 10;
        if(digit != 0 && (n % digit != 0)){
            return false;
        }
        copy = copy / 10;
    }
    return true;
}

void solve(){
    ll n;
    cin >> n;

    while(!isFair(n)){
        n++;
    }

    cout << n << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}