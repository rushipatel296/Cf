#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    int idx_of_n = -1;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == n){
            idx_of_n = i;
        }
    }

    // Swap the maximum element 'n' with the first element
    swap(arr[0], arr[idx_of_n]);

    for(int i = 0; i < n; i++){
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
        
    return 0;
}