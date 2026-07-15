#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    // Write your solution here
    int a, b, c;
    cin >> a >> b >> c;
    if(c % 2 == 1){
        //katie starts
        if(a == b){
            cout << "First" << endl;
        }else if(a > b){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }else{
        //Anna starts
        if(a == b){
            cout << "Second" << endl;
        }else if(a > b){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}