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
    string s;
    cin >> s;

    int zero_count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            zero_count++;
        }
    }

    if(zero_count % 2 == 0){
        //bob always wins
        cout << "BOB" << endl;
        return;
    }else{

        zero_count--;
        if(zero_count == 0){
            cout << "BOB" << endl;
            return;
        }
        cout << "ALICE" << endl;
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