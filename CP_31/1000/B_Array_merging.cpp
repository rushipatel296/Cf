#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    // vector<int> c(2 * n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<int> longest_sub_a(2 * n + 1, 0);
    vector<int> longest_sub_b(2 * n + 1, 0);

    int counter = 1;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            counter++;
        }else{
            longest_sub_a[a[i - 1]] = max(longest_sub_a[a[i - 1]], counter);
            counter = 1;
        }
    }
    longest_sub_a[a[n - 1]] = max(longest_sub_a[a[n - 1]], counter);

    counter = 1;

    for(int i = 1; i < n; i++){
        if(b[i] == b[i - 1]){
            counter++;
        }else{
            longest_sub_b[b[i - 1]] = max(longest_sub_b[b[i - 1]], counter);
            counter = 1;
        }
    }
    longest_sub_b[b[n - 1]] = max(longest_sub_b[b[n - 1]], counter);
    int ans = 0;
    for(int i = 0; i < 2 * n + 1; i++){
        ans = max(longest_sub_a[i] + longest_sub_b[i], ans);
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