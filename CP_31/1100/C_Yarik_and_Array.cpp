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

    int max_sum = INT_MIN;
    int i = 0;
    int j = 0;
    int cur_sum = 0;
    while(i < n && j < n){
        if(i == j || (i != j && abs(arr[j] - arr[j - 1]) % 2 == 1)){
            // cout << "expanding cur window" << endl;
            cur_sum += arr[j];
            if(cur_sum < 0){
                // cout << "Cur is negative : " << cur_sum << endl;
                // cout << "Creating new window from next element" << endl;
                // cur_sum -= arr[j];
                max_sum = max(cur_sum, max_sum);
                cur_sum = 0;
                j++;
                i = j;
                continue;
            }
            // cout << "Cur Sum : " << cur_sum << endl;
            j++;
        }else if(i != j && abs(arr[j] - arr[j - 1]) % 2 == 0){
            i = j;
            // cout << "Start new Window from index " << i << endl;
            max_sum = max(max_sum, cur_sum);
            // cout << "Updating the previous windows sum : " << cur_sum << endl;
            cur_sum = 0;
            continue;
        }
        // }else{
        //     cout << "new window with one element at index " << i << endl;
        //     cur_sum = arr[i];
        //     j++;
        // }
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}