#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x;
    cin >> s;
    int count = 0;
    int i = 0;

    while(i <= 5){
        int res = x.find(s);
        if (res != string::npos){
            cout << count << endl;
            return;
        }else{
            x = x + x;
            count++;
        }
        i++;
    }
    cout << "-1" << endl;
    return;

}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}