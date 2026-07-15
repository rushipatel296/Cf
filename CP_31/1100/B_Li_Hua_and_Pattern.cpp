#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    bool ans = true;
    int count = 0;
    for(int i = 0; i < (n + 1)/ 2; i++){
        // cout << "Row : " << i << endl;
        vector<int>& a = grid[i];
        vector<int>& b = grid[n - 1 - i];
        // reverse(b.begin(), b.end());

        for(int j = 0; j < n; j++){
            if(a[j] ^ b[n - 1 - j]){
                a[j] = b[n - 1 - j];
                // cout << "for the " << i << "th row, " << j << "th cell does not match a[j] =  " << a[j] << endl;
                count++;
            }
            if(count > k){
                ans = false;
                break;
            }
        }
    }

    // cout << "Debug- operations : " << count << endl;
    if(k > count){
        int rem = k - count;
        if(rem % 2 == 1 && (n % 2) == 0){
            ans = false;
        }
    }
    if(!ans){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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