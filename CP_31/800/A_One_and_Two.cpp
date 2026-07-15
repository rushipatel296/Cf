#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    int count = 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 2){
            count++;
        }
    }
    if(count % 2 == 1){
        cout << -1 << endl;
        return;
    }
    int cur = 0;    
    for(int i = 0; i < n; i++){
        if(arr[i] == 2){
            cur++;
        }
        if(cur == (count / 2)){
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}