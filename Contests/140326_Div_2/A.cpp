#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n * n);
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[idx];
            idx++;
        }
    }

    unordered_map<int, int> freq;
    int maxi = 0; 
    
    for(int i = 0; i < n * n; i++){
        freq[arr[i]]++;
        maxi = max(maxi, freq[arr[i]]);
    }
    
    // The maximum allowed frequency is n^2 - n
    if(maxi <= n * n - n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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