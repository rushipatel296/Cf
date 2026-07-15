#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<ll> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<ll> prefix_sum(n);
    for(int i = 0; i < n; i++){
        prefix_sum[i] = h[i] + (i - 1 >= 0 ? prefix_sum[i - 1] : 0);
    }

    vector<ll> max_h_so_far(n);
    max_h_so_far[0] = h[0];

    for(int i = 1; i < n; i++){
        max_h_so_far[i] = max(h[i], max_h_so_far[i - 1]);
    }


    while(q--){
        int legs;
        cin >> legs;


        //find the first height > legs in max_h_so_far

        int lo = 0;
        int hi = n - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(max_h_so_far[mid] <= legs){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        int index = lo;
        if(max_h_so_far[lo] <= legs){
            index++;
        }
        ll ans = 0;
        if(index - 1 >= 0){
            ans = prefix_sum[index - 1];
        }
        cout << ans << " ";
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