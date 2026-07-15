#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, k;
    string s;
    cin >> n >> k;

    cin >> s;

    unordered_map<char, int> count;

    for(int i = 0; i < n; i++){
        count[s[i]]++;
    }

    int odd_count = 0;
    for(auto ele : count){
        if(ele.second % 2 == 1){
            odd_count++;
        }
    }

    if(odd_count >= k){
        if(odd_count - k > 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        //if you have to remove more chars than odd freq chars -> you will always have a palindrome right?
        cout << "YES" << endl;

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