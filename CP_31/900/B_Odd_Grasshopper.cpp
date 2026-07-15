#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll x, n;
    cin >> x >> n;
    ll remain = n % 4;
    if(remain == 0){
        cout << x << endl;
        return;
    }
    ll finalpos = x;
    if(x % 2 == 0){
        if(remain == 1){
            finalpos -= n;
        }else if(remain == 2){
            finalpos += 1; 
        }else{
            finalpos++;
            finalpos += n;
        }
    }else{
        if(remain == 1){
            finalpos += n;
        }else if(remain == 2){
            finalpos--;
        }else{
            finalpos--;
            finalpos -= n;
        }
    }
    cout << finalpos << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}