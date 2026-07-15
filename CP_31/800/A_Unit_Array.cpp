#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    int neg = 0;
    int pos = 0;

    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        if(ele == -1){
            neg++;
        }else{
            pos++;
        }
    }
    int ans = 0;
    while(pos < neg){
        pos++;
        neg--;
        ans++;
    }   //condition 1 satisfied (sum >= 0)
    if(neg % 2 == 1){ // condition 2 satisfy
        pos++;
        neg--;
        ans++;
    }
    cout <<ans << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}