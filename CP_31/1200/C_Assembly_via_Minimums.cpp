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
    int size = (n * (n - 1)) / 2;
    vector<int> arr(size);
    for(int i = 0; i < size; i++) cin >> arr[i];

    unordered_map<int, int> freq;
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }

    vector<pair<int, int>> temp; // ele, freq
    for(auto ele : freq){
        temp.push_back({ele.first, ele.second}); // should store element with its freq
    }

    sort(all(temp));
    vector<int> ans(n);

    int index = 0;
    for(auto ele : temp){
        int freq_allowed = n - 1 - index;
        int element = ele.first;
        int f = ele.second;
        
        while(f >= freq_allowed && index < n){
            ans[index] = element;
            f = f - (n - 1 - index);
            index++;
            freq_allowed = n - 1 - index;
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}