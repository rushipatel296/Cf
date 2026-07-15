#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;
    int z_count = 0;
    int o_count = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            z_count++;
        }else{
            o_count++;
        }
    }

    int chances = min(z_count, o_count);

    if(chances % 2 == 0){
        cout << "NET" << endl;
    }else{
        cout << "DA" << endl;
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