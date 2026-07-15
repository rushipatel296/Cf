#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);

    for(int i = 1; i < n + 1; i++){
        cin >> arr[i];
    }

    vector<int> delta(n + 1, 0);
    int sum = 0;

    for(int i = 1; i <= n; i++){
        delta[i] = arr[i] - i;
        cout << delta[i] << " ";
        sum += delta[i];
    }
    cout << endl;


    if(sum == 0){
        cout << "YES" << endl;
    }
    else{
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