#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n ;
    cin >> n;
    // int ans = -1;
    int steps = 0;

    while(n > 1){
        int rem = n % 6;
        if(rem == 0){
            n = n/6;
            steps++;
        }else if(rem == 1 || rem == 2 || rem == 4 || rem == 5){
            steps = -1;
            break;
        }else{
            // n = n * 2;
            steps++;
            // n = n / 6;
            n = n / 3; 
            steps++;
        }
    }
    if(n == 1){
        cout << steps << endl;
    }else{
        cout << -1 << endl;
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