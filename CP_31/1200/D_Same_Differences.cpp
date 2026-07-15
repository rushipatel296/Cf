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
    
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        v[i] = arr[i] - i;
    }

    map<int, int> freq;
    for(int i = 1; i <= n; i++){
        freq[v[i]]++;
    }  
    ll ans = 0;

    for(auto ele : freq){
        // cout << "ele : " << ele.first << " freq : " << ele.second << endl;
        if(ele.second >= 2){
            int f = ele.second;
            ans += (1LL * f * (f - 1)) / 2;
        }
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