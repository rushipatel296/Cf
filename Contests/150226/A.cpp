#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n ;
    cin >> n;
    // bool is_one = false;
    bool is_six = false;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        if(ele == 67){
            is_six = true;
        }

    }

    if(is_six){
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