#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n - 1;
    int count = 0;
    while(i <= j){
        int cur_power = 0;
        cur_power += arr[j];
        int k = arr[j];
        j--;
        int remaining = j - i + 1;
        while(cur_power <= d && remaining > 0){
            cur_power += k;
            i++;
            remaining--;
            if(i > j) break;
        }
        if(cur_power > d) count++;

    }
    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}