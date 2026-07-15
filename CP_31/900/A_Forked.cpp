#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int a, b, k_x, k_y, q_x, q_y;

    cin >> a >> b >> k_x >> k_y >> q_x >> q_y;

    set<pair<int, int>> s1;
    set<pair<int, int>> s2;
    set<pair<int, int>> intersectionSet;

    vector<pair<int,int>> possibilities = {
        {a, b}, {b, a}, {a, -b}, {-b, a}, {-a, b}, {b, -a}, {-a, -b}, {-b, -a}
    };

    for(auto ele : possibilities){

        int x = k_x + ele.first;
        int y = k_y + ele.second;

        s1.insert({x, y});

        int p = q_x + ele.first;
        int q = q_y + ele.second;

        s2.insert({p, q});
    }
    int ans = 0;
    for(auto ele : s1){
        if(s2.find(ele) != s2.end()){
            ans++;
        }
    }

    cout << ans << endl;

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