#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k, max_temp;
    cin >> n >> k >> max_temp;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long num_ways = 0;
    long long cur = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] <= max_temp){
            cur++;
        }else{
            if(cur >= k){
                long long diff = cur - k + 1;
                num_ways += (diff * (diff + 1)) / 2 ; 
            }
            cur = 0; // Reset 
        } 
    }
    if(cur >= k){
        long long diff = cur - k + 1;
        num_ways += (diff * (diff + 1)) / 2 ; 
    }

    cout << num_ways << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}