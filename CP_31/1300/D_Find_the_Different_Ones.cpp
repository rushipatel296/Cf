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

    int q;
    cin >> q;

    while(q--){//O(qlogn)
        int l, r;
        cin >> l >> r;

        auto it = lower_bound(arr.begin() + l - 1, arr.begin() + r - 1, arr[l] + 1); //O(logn)
        auto it2 = upper_bound(arr.begin() + l - 1, arr.begin() + r - 1, arr[l] - 1); //O(logn) //first element smaller than arr[l]

        if((it == arr.end() && (*arr.end() < arr[l])) && (it2 == arr.end() && arr[l] < *arr.end())){
            cout << -1 << " " << -1; 
        }else{
            if(it != arr.end()){
                cout << l + 1 << " " << it - arr.begin() + 1 << endl;
            }else{
                cout << l + 1 << " " << it2 - arr.begin() + 1 << endl;
            }
        }
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