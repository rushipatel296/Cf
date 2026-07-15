#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> right_freq;
    unordered_map<char, int> left_freq;

    for(int i = 0; i < n; i++){
        right_freq[s[i]]++;
    }
    int ans = 0;

    for(int i = 1; i < n; i++){
        left_freq[s[i - 1]]++;
        right_freq[s[i - 1]]--;
        if(right_freq[s[i - 1]] == 0){
            right_freq.erase(s[i - 1]);
        }

        ans = max(ans, (int)(left_freq.size() + right_freq.size()));
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