#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

vector<int> factors(int n){
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }

    sort(all(ans));
    return ans;
}

void solve(){
    int n;
    cin >> n;
    ll ans = INF;
    vector<int> f = factors(n);

    int a = 0, b = 0;
    for(int i = 0; i < f.size(); i++){
        int p = f[i];
        int q = n - p;
        ll candidate = lcm(p, q);
        if(candidate < ans){
            ans = candidate;
            a = p;
            b = q;
        }
    }
    cout << a << " " << b << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}