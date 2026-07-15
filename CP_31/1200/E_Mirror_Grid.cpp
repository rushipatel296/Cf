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
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = s[j] - '0';
        }
    }
    int ops = 0;

    vector<vector<bool>> done(n, vector<bool> (n, false));
    for(int i = 0; i <= (n / 2); i++){
        for(int j = 0; j <= (n / 2); j++){
            if(done[i][j] || done[j][n - 1 - i] || done[n - 1 - i][n - 1 - j] || done[n - 1 - j][i]) continue;

            int a = grid[i][j];
            int b = grid[j][n - 1 - i];
            int c = grid[n - 1 - i][n - 1 - j];
            int d = grid[n - 1 - j][i];
            int s = a + b + c + d;
            if(s == 3){
                s = 1;
            }
            else if(s == 4){
                s = 0;
            }
            ops += s;
            done[i][j] = true;
            done[j][n - 1 - i] = true;
            done[n - 1 - i][n - 1 - j] = true;
            done[n - 1 - j][i] = true;

        }
    }
    cout << ops << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}