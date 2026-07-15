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

    //maintain an array containing count of distinct chars encountered till each index

    // vector<int> distinct(n);

    unordered_map<int, int> freq;
    int count = 0;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
        // distinct[i] = freq.size();
        count += freq.size();

    }
    cout << count << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}