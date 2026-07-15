#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll a_b = lcm(a, b);
    ll b_c = lcm(b, c);
    ll a_c = lcm(a, c);

    ll a_b_c = lcm(a, b_c);
    ll all_together = m / a_b_c;

    ll only_ab = (m/a_b) - all_together;
    ll only_bc = (m/b_c) - all_together;
    ll only_ac = (m/a_c) - all_together;


    // ll only_a = (m/a) - (m/a_b) - (m/a_c) - (m/a_b_c);
    ll only_a = (m/a) - only_ab - only_ac - all_together;
    ll only_b = (m/b) - only_ab - only_bc - all_together;
    ll only_c = (m/c) - only_ac - only_bc - all_together;

    ll two_together = only_ab + only_ac + only_bc;

    ll alice = only_a * 6 + (only_ac + only_ab) * 3 + all_together * 2;
    ll bob = only_b * 6 + (only_bc + only_ab) * 3 + all_together * 2;
    ll carol = only_c * 6 + (only_ac + only_bc) * 3 + all_together * 2;
    // ll ans = (only_a + only_b + only_c) * 6 + (two_together) * 3 + all_together * 2;
    cout << alice << " " << bob << " " << carol << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}