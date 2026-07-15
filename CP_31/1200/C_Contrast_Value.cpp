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
    for(int i = 0; i < n; i++) cin >> arr[i];

    auto end = unique(arr.begin(), arr.end());
    arr.erase(end, arr.end());
    int size = arr.size();
    if(size == 1){
        cout << 1 << endl;
        return;
    }
    int count = 0;
    // vector<int> ans;
    // ans.push_back(arr[0]);
    count++;
    for(int i = 1; i < size - 1; i++){
        if((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])){
            count++;
            // ans.push_back(arr[i]);
        }
    }
    // ans.push_back(arr[size - 1]);
    count++;
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