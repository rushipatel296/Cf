#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int i1, i2;
    // unordered_map<int, int> idx_of;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // idx_of[arr[i]] = i;

        maxi = max(maxi, arr[i]);
        if(maxi == arr[i]) i1 = i;
        mini = min(mini, arr[i]);
        if(mini == arr[i]) i2 = i;
    }

    if(i1 == i2 - 1){
        cout << maxi - mini << endl;
        return;
    }

    //else there are two options - rotate maxi to nth pos OR rotate mini to 1st pos

    int option1 = arr[n - 1] - mini;
    int option2 = maxi - arr[0];

    int cur_max = max(option1, option2);
    for(int i = 0; i < n - 1; i++){
        cur_max = max(cur_max, arr[i] - arr[i + 1]);
    }
    cout << cur_max << endl;
    // cout << max(option1, option2) << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}