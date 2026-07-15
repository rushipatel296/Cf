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
    sort(arr.begin(), arr.end());
    int freq = 1; 
    int cur = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == arr[i - 1]){
            cur++;
        }else{
            cur = 1;
        }
        freq = max(freq, cur);
    }
    int remain = n - freq;
    int ops = 0;
    while(remain > 0){
        ops++; //one operation to clone the array
        ops = ops + min(freq, remain);
        remain = max(remain - freq, 0);
        freq = freq + min(freq, remain);
    }
    cout << ops << endl;
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