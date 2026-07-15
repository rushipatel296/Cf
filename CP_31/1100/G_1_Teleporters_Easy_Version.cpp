#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // cout << "Cost array : " << endl;
    for(int i = 0; i < n; i++){
        a[i] += i + 1;
        // cout << a[i] << " ";
    }
    // cout << endl;
    sort(all(a));
    ll cost_so_far = 0;
    int i = 0;
    int count = 0;
    while(cost_so_far < c && i < n){
        if(cost_so_far + a[i] <= c){
            // cout << "Adding " << a[i] << " to the cost so far and incrementing count : " << endl;
            cost_so_far += a[i];
            i++;
            count++;
        }else{
            break;
        }
    }
    cout << count << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}