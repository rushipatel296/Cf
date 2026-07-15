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

    map<ll, int> freq;
    ll sum = 0;
    bool ans = false;
    freq[sum]++;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            sum += arr[i];
        }else{
            sum -= arr[i];
        }
        if(freq.count(sum) > 0){
            ans = true;
            break;
        }else{
            freq[sum]++;
        }
    }

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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