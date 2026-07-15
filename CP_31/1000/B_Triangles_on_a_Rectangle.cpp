#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int w, h;
    cin >> w >> h;

    ll A_2 = 0;
    for(int i = 0; i < 4; i++){
        int k;
        cin >> k;
        int low = INT_MAX;
        int high = INT_MIN;
        while(k--){
            int pt ;
            cin >> pt;
            low = min(low, pt);
            high = max(high, pt);

        }
        if(i < 2){
            A_2 = max(A_2, (1LL * (high - low) * h));
        }else{
            A_2 = max(A_2, (1LL * w * (high - low)));
        }
    }

    cout << A_2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}