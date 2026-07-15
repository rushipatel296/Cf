#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;

    int neg_count = 0;
    int mini = INT_MAX;
    ll sum = 0;
    for(int i = 0; i < n * m; i++){
        int ele;
        cin >> ele;

        if(ele <= 0){
            neg_count++;
        }

        mini = min(mini, abs(ele));
        sum += abs(ele);
    }

    if(neg_count % 2 == 1){
        sum -= 2 * abs(mini);
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