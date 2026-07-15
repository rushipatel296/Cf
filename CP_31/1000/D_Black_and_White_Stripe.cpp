#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    string s; 
    cin >> s;

    int min_conv = INT_MAX;
    int cur_count = 0;
    int i = 0;
    int start = 0;
    int end = k - 1;
    for(; i < k; i++){
        if(s[i] == 'W'){
            cur_count++;
        }
    }
    min_conv = cur_count;
    // cout << "Window from index : " << start << " to " << end << " , W count : " << cur_count << endl;

    for(; i < n; i++){
        if(s[start] == 'W'){
            cur_count--;
        }
        start++;
        end = i;
        if(s[end] == 'W'){
            cur_count++;
        }
        // cout << "Window from index : " << start << " to " << end << " , W count : " << cur_count << endl;
        min_conv = min(min_conv, cur_count);
    }

    cout << min_conv << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}