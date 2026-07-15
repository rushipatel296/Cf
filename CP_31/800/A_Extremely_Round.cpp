#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int helper(int n, vector<int>& memo){
    if(n == 1){
        return memo[n] = 1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    int smallAns = helper(n - 1, memo);
    int copy = n;
    while(copy % 10 == 0){
        copy = copy / 10; //removes all the zeroes
    }

    if(copy <= 9 && copy >= 1){
        smallAns++;
    }
    return memo[n] = smallAns;
}

void solve() {
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    int ans = helper(n, memo);
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