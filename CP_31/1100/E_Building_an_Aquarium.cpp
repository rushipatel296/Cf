#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n, x;
    cin >> n >> x;

    vector<ll> heights(n);
    

    for(ll i = 0; i < n; i++){
        cin >> heights[i];
    }

    // sort(heights.begin(), heights.end());

    

    ll l = 1, h =  2 * 1e9;
    ll ans = 0;

    while(l <= h){
        ll mid = l + (h - l) / 2;

        ll water = 0;

        for(ll i = 0; i < n; i++){
            water += max(1LL * 0, mid - heights[i]);
        }

        if(water > x){
            h = mid - 1;
        }
        else{
            ans = mid;
            if(water == x){   
                break;
            }
            l = mid + 1;
        }
    }
    cout << ans << endl;
    // for(ll i = n - 1; i >= 0; i--){
    //     water += (heights[n - 1] - heights[i]);
    // }

    // ll i = 0;
    // ll j = n - 1;
    // ll cur_height = heights[n - 1];
    // // cout << water << endl;
    // while(water > x){
    //     cur_height = heights[j]; // this is the maximum height for this iteration
        
    //     ll diff = ((j + 1 < n) ? (heights[j + 1] - cur_height) : 0);
    //     water -= diff;
    //     while(j - 1 >= 0 && heights[j - 1] == heights[j]){
    //         j--;
    //         water -= diff; 
    //     }
    //     cout << "Cur Height : " << cur_height << endl;
    //     cout << "Cur Water : " << water << endl;

    //     // water -= (j - i) * diff;
    //     j--;
    // }

    // cout << cur_height << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}