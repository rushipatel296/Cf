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

    vector<pair<int,int>> a(n);

    for(int i = 0; i < n; i++){
        a[i] = {arr[i], i};
    }

    sort(a.rbegin(), a.rend());

    int end = n - 1;
    int start = 0;
    int ops = 0;
    int rem = end - start + 1;
    int j = 0;
    while(rem > 0 && j < n){
        auto top = a[j];
        int idx = top.second;
        if(idx > end){
            j++;
            continue;
        }
        ops++;
        end = idx - 1;
        j++;
        rem = end - start + 1;
    }

    cout << ops << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}