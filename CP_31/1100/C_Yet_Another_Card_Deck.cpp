#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    vector<int> idx(51, -1);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        if(idx[arr[i]] == -1){
            idx[arr[i]] = i;
            // cout << "Index of " << arr[i] << " = " << i << endl;
        }
    }

    vector<int> q(t);
    for(int i = 0; i < t; i++){
        cin >> q[i];
    }

    vector<int> ans(t);
    for(int i = 0; i < t; i++){
        ans[i] = idx[q[i]] + 1;
        // cout << "Ele : " << q[i] << ", idx : "<< idx[q[i]] << endl;
        // cout << "Updating idx of " << q[i] << " to 0" << endl;
        
        for(int j = 0; j <= 50; j++){
            if(idx[j] != -1 && idx[j] < ans[i]){
                // cout << "Updating idx of " << j << " to " << idx[j] + 1 << endl;
                idx[j]++;
            }
        }
        idx[q[i]] = 0;
        // cout << "-----" << endl;
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
    // cin >> t;
    while(t--)
        solve();
}