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
    int i = n - 1;
    int ops = 0;
    while(i > 0){
        while(i - 1 >= 0 && arr[i - 1] == arr[n - 1]){
            i--;
        }
        if(i == 0) break;
        int size = n - i;
        i = max(i - size, 0);
        ops++;
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