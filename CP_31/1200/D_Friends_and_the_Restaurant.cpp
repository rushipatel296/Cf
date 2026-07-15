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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> delta(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        delta[i] = b[i] - a[i];
        sum += delta[i];
    }

    sort(all(delta));
    int i = 0;
    int j = n - 1;
    int count = 0;
    while(i < j){
        if(delta[i] + delta[j] >= 0){
            count++;
            i++;
            j--;
        }else{
            i++;
        }
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