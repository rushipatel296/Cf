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

    string s ;
    cin >> s;

    bool possible = false;
    int l = -1, r = -1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i + 1]){
            possible = true;
            l = i + 1;
            r = i + 2;
            break;
        }
    }

    if(!possible){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl << l << " " << r << endl; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}