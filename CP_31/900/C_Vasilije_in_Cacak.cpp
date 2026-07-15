#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

long long sumation(long long n){
    long long ans = (n * (n + 1)) / 2;
    return ans;
}

void solve() {
    long long n, k, sum;
    cin >> n >> k >> sum;

    long long largest_k_sum = 0;
    long long smallest_k_sum = 0;

    //compute the largest k sum 
    largest_k_sum = sumation(n) - sumation(n - k);
    // for(int i = n; i >= n - k + 1; i--) largest_k_sum += i;
    smallest_k_sum = sumation(k);
    // for(int i = 1; i <= k; i++) smallest_k_sum += i;

    if(sum <= largest_k_sum && sum >= smallest_k_sum){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
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