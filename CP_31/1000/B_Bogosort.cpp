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

    sort(arr.rbegin(), arr.rend());

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << "Debug : " << endl;
    // for(int i = 0; i < n; i++){
    //     cout << i + 1 - arr[i] << " ";
    // }
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}