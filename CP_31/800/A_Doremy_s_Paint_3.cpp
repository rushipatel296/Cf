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

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //there can only be 2 distinct nums at max w f1 - f2 == 1
    int num1 = INT_MAX;
    int num2 = INT_MAX;
    int f1 = 0;
    int f2 = 0;
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(arr[i] == num1){
            f1++;
        }else if(arr[i] == num2){
            f2++;
        }
        else if(num1 == INT_MAX){
            num1 = arr[i];
            f1 = 1;
        }else if(num2 == INT_MAX){
            num2 = arr[i];
            f2 = 1;
        }else{
            ans = false;
            break;
        }
    }
    // cout << "num 1 : " << num1 << " f1 : " << f1 << endl << "num 2 : " << num2 << " f2 : " << f2 << endl;
    if(num1 != INT_MAX && num2 != INT_MAX && (ans == false || (abs(f1 - f2) > 1))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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