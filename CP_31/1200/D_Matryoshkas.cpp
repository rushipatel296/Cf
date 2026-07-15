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

    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    sort(all(arr));
    auto end = unique(arr.begin(), arr.end());

    arr.erase(end, arr.end());
    int size = arr.size();

    ll count = 0;
    for(int i = 0; i < size; i++){
        count += max(freq[arr[i]] - freq[arr[i] - 1], 0);
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