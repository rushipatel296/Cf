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

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int i = 0; 
    int j = n - 1;
    ll sumA = 0, sumB = 0;
    int ans = 0;
    int rem = j - i + 1;
    while(i <= j){
       if(sumA <= sumB){
            sumA += arr[i];
            i++;
        }else{
            sumB += arr[j];
            j--;
       }

       if(sumA == sumB){
            ans = max(ans, i + (n - 1 - j));
       }
    }

    cout << ans << endl;
    // unordered_map<int, int> pos;
    // int sum = 0;
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    //     pos[sum] = i;
    // }
    // sum = 0;
    // int ans = 0;
    // for(int i = n - 1; i >= 0; i--){
    //     sum += arr[i];

    //     if(pos.count(sum) > 0 && pos[sum] < i){
    //         ans = max(ans, (pos[sum] + 1) + (n - 1 - i + 1));
    //     }
    // }
    // cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}