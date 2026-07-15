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
    string s;
    cin >> s;
    
    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        arr[i] = s[i - 1] - '0';
        // cout << arr[i] << " ";
    }
    // cout << endl;

    vector<bool> deleted(n + 1);

    ll cost = 0;
    for(int i = 1; i <= n; i++){
       for(int j = 1; i * j <= n; j++){
            ll current_multiple = 1LL * i * j;
            if(arr[current_multiple] == 1){
                break;
            }
            if(arr[current_multiple] == 0 && !deleted[current_multiple]){
                cost += 1LL * i;
                deleted[current_multiple] = true;
            }
       }
    }
    cout << cost << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}