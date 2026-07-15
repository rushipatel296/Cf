#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    vector<int> arr(n);
    int ans = -1;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i == 0) {
            ans = arr[i];
        }
        ans = ans & arr[i];
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}