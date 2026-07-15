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
    int count = 0;
    for(int i = n - 2; i >= 0; i--){
        while(arr[i] >= arr[i + 1]){
            arr[i] = arr[i] / 2;
            count++;
            if(arr[i] == 0){
                break;
            }
        }
        if(arr[i] == 0 && arr[i + 1] == 0){
            count = -1;
            break;
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