#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){ 
    string s; 
    cin >> s;
    int n = s.size();
    //find the longest contiguos segment of 1s.
    int maxi = INT_MIN;
    int cur = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            cur++;
        }else{
            maxi = max(maxi, cur);
            cur = 0;
        }
    }
    maxi = max(maxi, cur);
    if(maxi == n){
        cout << 1LL * n * n << endl;
        return;
    }
    int i = 0, j = n - 1;
    cur = 0;
    //this will capture the wraparound maxi length
    while((s[i] == '1' || s[j] == '1') && i < j){
        if(s[i] == '1'){
            cur++;
            i++;
        }
        if(s[j] == '1'){
            cur++;
            j--;
        }
        maxi = max(maxi, cur);
    }
    // cout << "maximum consec 1s found in the string = " << maxi << endl;
    ll ans = 0;
    for(int h = 1; h <= (maxi + 1) / 2; h++){
        int w = maxi + 1 - h;
        // cout << "H : " << h << " W : " << w << endl;
        ans = max(ans, 1LL * h * w);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}