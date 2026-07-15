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
    for(int i = 1; i < n + 1; i++) cin >> arr[i];

    map<int, int> idx;
    for(int i = 1; i <= n; i++){
        idx[arr[i]] = i;
    }

    int count = 0;
    for(int i = 1; i < n + 1; i++){
        for(int x = 1; arr[i] * x <= i + n; x++){
            
            if(x == arr[i]) continue;
            if(idx.count(x) > 0){
                int j = idx[x];
                if(j > i && ((arr[i] * arr[j]) == i + j)){
                    // cout << "arr[i] : " << arr[i] << " i : " << i << endl;
                    // cout << "arr[j] : " << arr[j] << " j : " << j << endl;
                    count++;
                    // cout << "Cur count : " << count << endl;
                }
            }
        }
    }

    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}