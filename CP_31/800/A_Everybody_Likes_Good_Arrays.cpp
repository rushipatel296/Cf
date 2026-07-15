#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] % 2 == 1 && arr[i - 1] % 2 == 1){
            //cur and prev both are odd -> combine
            count++;
        }else if(arr[i] % 2 == 0 && arr[i - 1] % 2 == 0){
            //cur and prev both are even -> combine
            count++;
        }else{
            continue;
        }
    }
    cout << count << endl;
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