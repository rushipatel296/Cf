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
    string a, b;
    cin >> a >> b;
    
    vector<bool> flippable(n, false);
    vector<bool> is_same(n, false);

    int ones = 0; 
    int zeros = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '1'){
            ones++;
        }else{
            zeros++;
        }
        if(ones == zeros){
            flippable[i] = true;
        }
        if(a[i] == b[i]){
            is_same[i] = true;
        }
    }
    bool ans = true;
    for(int i = 0; i < n - 1; i++){
        if((is_same[i] != is_same[i + 1]) && (flippable[i] == false)){
            ans = false;
            break;
        }
    }

    if(is_same[n - 1] == false && flippable[n - 1] == false){
        ans = false;
    }

    if(ans){
        cout << "YES" << endl;
    }else{
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