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
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> marked(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(marked[i] == 1){
            break;
        }
        if(arr[i] <= i){
            marked[i] = 1;
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(marked[i] == 1){
            count++;
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