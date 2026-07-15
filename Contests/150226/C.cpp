#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ops = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1] || arr[i] == (7 - arr[i - 1])){
            // ops++;
            //not allowed ints - arr[i - 1] , 7 - arr[i - 1], arr[i + 1], 7 - arr[i + 1]
            // int candidate;
            for(int j = 1; j <= 6; j++){
                if(j != arr[i - 1] && j != (7 - arr[i - 1])){
                    if(i + 1 < n){
                        if(j != arr[i + 1] && j != (7 - arr[i + 1])){
                            // cout << arr[i] << " is now " << j << endl;
                            arr[i] = j;
                            ops++;
                            break;
                        }
                    }else{
                        // cout << arr[i] << " is now " << j << endl;
                        arr[i] = j;
                        ops++;
                        break;
                    }
                    
                }
            }
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