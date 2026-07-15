#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n * k);
    for(ll i = 0; i < n * k; i++){
        cin >> arr[i];
    }

    int size = n * k ;
    int m = ceil(n / 2.0);
    // cout << "M : " << m << endl;
    int front = m - 1;
    int back = n - front;
    long long ans = 0;
    for(int i = 1; i <= k; i++){
        ans += arr[size - (i * back)];
        // cout << "Debug : adding ele " << arr[size - (i * back)] << " to median sum" << endl; 
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