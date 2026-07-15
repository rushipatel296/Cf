#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n ;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = -1; 
    int end = -1;   
    int flag = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(start == -1 && end == -1){
            start = i;
            end = i;
        }
        if(arr[i] == arr[start]){
            end = i;
        }else{
            // cout << "encountered a diff ele : " << arr[i] << " than " << arr[start] << " (start)" << endl;
            int window_size = end - start + 1;

            if(window_size == 1){
                flag = 1;
                break;
            }
            
            for(int j = end - 1; j >= start; j--){
                ans[j] = j + 2; //additional one for converting to 1 based indexing
            }
            ans[end] = start + 1;

            start = i;
            end = i;
        }
    }
    int window_size = end - start + 1;

    if(window_size == 1){
        flag = 1;
    }
    // cout << "end : " << end  << " start : " << start << endl;
    for(int j = end - 1; j >= start; j--){
        // cout << "j : " << j << endl;
        ans[j] = j + 2; //additional one for converting to 1 based indexing
    }
    ans[end] = start + 1;

    if(flag){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}