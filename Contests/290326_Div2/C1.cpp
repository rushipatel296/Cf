#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int b_val;
        cin >> b_val; 
    }


    // vector<int> ans(n);
    int ops = 0;
    //gcd[i] = gcd(arr[i + 1], arr[i])
    for(int i = 0; i < n; i++){
        ll L;
        if(i == 0){
            L = gcd(a[0], a[i + 1]);
        }else if(i == n - 1){
            L = gcd(a[n - 1], a[n - 2]);
        }else{
            L = lcm((ll)gcd(a[i], a[i - 1]), (ll)gcd(a[i], a[i + 1]));
        }

        if(L < a[i]){
            ops++;
        }
    }
    cout << ops << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}