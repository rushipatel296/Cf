#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;


void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int i = 0;
    int j = 0;
    int cur_sum = 0;

    int total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum += arr[i];
    }
    if(total_sum < s){
        cout << -1 << endl;
        return;
    }
    int max_len = -1;

    while(j < n){
        cur_sum += arr[j];

        while(cur_sum > s && i <= j){
            cur_sum -= arr[i];
            i++;
        }
        if(cur_sum == s){
            max_len = max(max_len, j - i + 1);
        }
        j++;
    }
    if(max_len == -1){
        cout << -1 << endl;
    }else{
        cout << n - max_len << endl;
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