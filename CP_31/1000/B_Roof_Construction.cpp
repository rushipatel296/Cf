#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    n--;

    int msb = log2(n);
    int num = pow(2, msb) - 1;
    vector<int> ans;

    while(num >= 0){
        ans.push_back(num);
        num--;
    }

    num = pow(2, msb);
    while(num <= n){
        ans.push_back(num);
        num++;
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}