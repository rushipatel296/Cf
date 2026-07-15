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

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll sum = 0;
    int neg_count = 0;
    int mini = INT_MAX;
    for(int i = 0; i < a.size(); i++){
        sum += abs(a[i]);
        if(a[i] <= 0){
            neg_count++;
        }
        mini = min(mini, abs(a[i]));
    }
    if(neg_count % 2 == 1){
        sum -= 2 * mini;
    }
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}