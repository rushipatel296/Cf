#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> diff(n - 1);
    for(int i = 1; i < n; i++){
        diff[i - 1] = arr[i] - arr[i - 1];
    }

    vector<int> ans(n, INT_MAX);
    ll sumation = 0;
    ll x = 0;
    for(int i = 1; i < n - 1; i++){
        // cout << "a" << i - 1 << " = " << diff[i + 1] << " - " << diff[i] << " / 2" << endl;
        ans[i] = (diff[i] - diff[i - 1]) / 2;
        sumation += i * ans[i];
        x += ans[i];
    }
    int last = (arr[0] - sumation) / (n - 1);
    ans[n - 1] = last;
    ans[0] = diff[0] + x + last;
    // cout << "DEBUG : " << endl;

    for(int i = 0; i < n; i++){
        cout << ans[i] << " " ;
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