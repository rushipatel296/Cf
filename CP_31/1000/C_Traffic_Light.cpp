#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    char ch;
    cin >> ch;

    string s;
    cin >> s;

    vector<int> dist(n, -1);
    int d = -1;
    int count = 0;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == ch) count++;

        if(s[i] == 'g'){
            d = 0;
        }else{
            if(d == -1) continue;
            d++;
        }
        dist[i] = d;
    }

    for(int i = n - 1; i >= 0; i--){
        if(dist[i] == -1 && i == n - 1){
            dist[i] = 1 + dist[0];
        }else if(dist[i] == -1){
            dist[i] = 1 + dist[i + 1];
        }
    }

    // cout << "Debug : " << endl;

    // for(int i = 0; i < n; i++){
    //     cout << dist[i] << " ";
    // }

    // cout << endl;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == ch){
            ans = max(ans, dist[i]);
        }
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