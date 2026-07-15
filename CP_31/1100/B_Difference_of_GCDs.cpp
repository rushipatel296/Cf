#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> arr(n);

    int idx = 0;
    bool ans = true;
    while(idx < n){
        int rem = l % (idx + 1);
        //gcd(arr[i], idx + 1) == idx + 1
        int ele = l + ((idx + 1 - rem) % (idx + 1));
        if(ele > r){
            ans = false;
            break;
        }
        arr[idx] = ele;
        idx++;
    }
    if(!ans){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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