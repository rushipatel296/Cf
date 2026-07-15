#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, r, b;
    cin >> n >> r >> b;
    int partitions = b + 1;
    int r_in_partition = r / partitions;
    int carry = r % partitions;
    string ans = "";
    while(partitions){
        // cout << "Debug Partition : " << partitions << endl;
        // ans += 'R' * r_in_partition;
        ans += string(r_in_partition, 'R');
        // cout << "After adding r_in_partition ans is  : " << ans << endl;
        if(carry > 0){
            ans += 'R';
            // cout << "Adding carry R to ans - ANS : " << ans << endl;
            carry--;
        }

        if(partitions != 1) ans += 'B';
        // cout << "This partition is complete : " << ans << endl;
        partitions--;
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