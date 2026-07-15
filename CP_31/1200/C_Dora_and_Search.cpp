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
    for(int i = 0; i < n; i++) cin >> arr[i];
    int i = 0;
    int j = n - 1;
    int U = n;
    int L = 1;
    bool ans = false;
    while(j - i + 1 >= 4){  //no answer exists for size < 4
        if(arr[i] == U){
            i++;
            U--;
        }else if(arr[i] == L){
            i++;
            L++;
        }else if(arr[j] == U){
            j--;
            U--;
        }else if(arr[j] == L){
            j--;
            L++;
        }else{
            ans = true;
            break;
        }
    }
    if(ans){
        cout << i + 1 << " " << j + 1 << endl;
    }else{
        cout << -1 << endl;
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