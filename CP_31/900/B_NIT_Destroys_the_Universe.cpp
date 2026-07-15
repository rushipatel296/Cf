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

    int window_count = 0;
    int start = -1;
    int end = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            if(start == -1){
                // cout << "window start at index : " << i << endl; 
                start = i;
                end = i;
                window_count++;
            }else{
                end = i;
                // cout << "window extending to index : " << i << endl;
            }
        }else{
            if(end != -1){
                start = -1;
                // cout << "window ended at index : " << i - 1 << "waiting to start new window" << endl;
            }
        }
    }
    // if(start != -1) window_count++; //for the fact if arr ends with non zero
    // cout << "Ans : " << window_count << endl;
    if(window_count == 0){
        cout << 0 << endl;
    }
    else if(window_count == 1){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
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