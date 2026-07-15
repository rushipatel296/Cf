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

    int maxi_ele = 0;
    int maxi_count = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxi_ele){
            maxi_ele = arr[i];
            maxi_count = 1;
        }else if(arr[i] == maxi_ele){
            maxi_count++;
        }
    }

    cout << maxi_count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}