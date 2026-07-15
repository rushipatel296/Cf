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
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    unordered_map<int, int> index_of;

    for(int i = 0; i < n; i++){
        index_of[arr[i]] = i;
    }


    int i = 0;
    int j = n - 1;
    unordered_map<int, bool> seen;
    while(i <= j){
        // cout << "i : " << i << " j : " << j << endl;
        seen[arr[i]] = true;
        seen[arr[j]] = true;

        if(arr[i] == n){
            i++;
            continue;
        }
        if(arr[j] == n){
            j--;
            continue;
        }

        int bigger = ((arr[i] > arr[j]) ? arr[i] : arr[j]);
        for(int k = bigger + 1; k <= n; k++){
            if(!seen[k]){
                cout << "YES" << endl;
                cout << i + 1 <<" " << index_of[k] + 1<< " " << j + 1<< endl;
                return;
            }
        }
        if(arr[i] == bigger){
            i++;
        }else{
            j--;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}