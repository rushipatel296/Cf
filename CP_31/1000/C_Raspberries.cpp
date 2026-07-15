#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(k == 2){
        int ans  = 1;
        for(int i = 0; i < n; i++){
            int modulo = arr[i] % 2;
            if(modulo == 0){
                ans = 0;
                break;
            }
        }
        cout  << ans << endl;

    }else if(k == 3){

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int modulo = arr[i] % 3;
            if(modulo == 0){
                ans = 0;
                break;
            }else{
                ans = min(ans,3 - modulo);
            }
        }
        cout  << ans << endl;
    }else if(k == 4){
        int ans = INT_MAX;
        int count_of_two = 0;
        int odd_count = 0;
        for(int i = 0; i < n; i++){
            int modulo = arr[i] % 4;
            if(modulo == 0){
                ans = 0;
                break;
            }else if (modulo == 2){
                count_of_two++;
                if(count_of_two == 2){
                    ans = 0;
                    break;
                }
            }
            else{
                odd_count++;
                // if(odd_count == 2){
                //     ans = 2;
                // }
                ans = min(ans,4 - modulo);
            }
        }

        if(count_of_two >= 2){
            ans = 0;
        }else if(count_of_two == 1){
            ans = min(1, ans);
        }else{
            ans = min(2, ans);
        }
        cout << ans << endl;
    }else{
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int modulo = arr[i] % 5;
            if(modulo == 0){
                ans = 0;
                break;
            }else{
                ans = min(ans, 5 - modulo);
            }
        }
        cout  << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}