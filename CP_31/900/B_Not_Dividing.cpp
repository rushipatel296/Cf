#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 1){
            arr[i]++;
        }
        if(arr[i] % arr[i - 1] == 0){
            arr[i]++;
        }
        
        cout << arr[i] << " ";
    }
    cout << endl;

    
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