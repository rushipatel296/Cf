#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> idx_of(n + 1, -1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        idx_of[arr[i]] = i;
    }

    int cur = INT_MIN;
    vector<bool> isugly(n);
    int uglyCount = 0;
    int mini_idx = -1;
    int maxi_idx = -1;
    for(int i = 0; i < n; i++){
        cur = max(cur, arr[i]);
        if(cur == i + 1){
            isugly[i] = true;
            // cout << arr[i] << " is ugly" << endl;
            uglyCount++;
            if(mini_idx == -1 && i != n - 1){
                mini_idx = i;
            }else{
                if(arr[i] < arr[mini_idx]){
                    mini_idx = i;
                }
            }

            // if(maxi_idx == -1){
            //     maxi_idx = i;
            // }else{
            //     if(arr[i] > arr[maxi_idx]){
            //         maxi_idx = i;
            //     }
            // }
        }
    }

    if(mini_idx != -1){
        // cout << "Swapping " << arr[mini_idx] << " with " << arr[idx_of[n]] << endl;
        swap(arr[mini_idx], arr[idx_of[n]]);

        if(mini_idx == idx_of[n]){
            swap(arr[mini_idx], arr[idx_of[1]]);
        }
    }
    // cout << "Final arr : " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}