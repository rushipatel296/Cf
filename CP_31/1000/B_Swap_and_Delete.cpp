#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;

    int c1 = 0, c0 = 0, ts = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            c0++;
        }else{
            c1++;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' && c1 > 0){
            c1--;
            ts++;
        }else if(s[i] == '1' && c0 > 0){
            c0--;
            ts++;
        }else{
            break;
        }
    }

    cout << s.size() - ts << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}