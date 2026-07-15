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

    map<int, int> freq_of_msb;

    for(int i = 0; i < n; i++){
        int ele = arr[i];
        
        //find the position of msb;
        int pos = 0;
        while(ele > 0){
            ele = ele / 2;
            pos++;
        }
        // cout << "element : " << arr[i] << " pos of MSB : " << pos << endl;
        freq_of_msb[pos]++;
    }
    ll ans = 0;

    for(auto [pos, count] : freq_of_msb){
        // cout << "position : " << pos << " count : " << count << endl;
        ans += (1LL * count * (count - 1)) / 2;
    }
    cout <<  ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}