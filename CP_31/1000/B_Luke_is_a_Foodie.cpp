#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, x;
    cin >> n >> x;

    int count = 0;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<pair<int, int>> vec(n);
    
    for(int i = 0; i < n; i++){
        int ub = arr[i] + x;
        int lb = arr[i] - x;
        vec[i] = {lb, ub};
    }
    int prev_lb = INT_MIN;
    int prev_ub = INT_MAX;
    for(int i = 0; i < n; i++){
        auto ele = vec[i];
        int lb = ele.first;
        int ub = ele.second;

        int cur_lb = max(prev_lb, lb);
        int cur_ub = min(prev_ub, ub);
        if(cur_lb > cur_ub){
            count++;
            prev_lb = lb;
            prev_ub = ub;
        }else{
            prev_lb = cur_lb;
            prev_ub = cur_ub;
        }
        
    }
    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}