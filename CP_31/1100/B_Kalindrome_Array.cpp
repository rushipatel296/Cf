#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

bool isPalindrome(vector<int>& arr, int candidate){
    int n = arr.size();

    int i = 0;
    int j = n - 1;
    bool ans = true;
    while(i <= j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }
        else{
            if(arr[i] == candidate){
                i++;
            }else if(arr[j] == candidate){
                j--;
            }else{
                ans = false;
                break;
            }
        }
    }
    // cout << "Ignoring " << candidate << ", Result : " << ans << endl;
    return ans;

}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int i = 0;
    int j = n - 1;
    int candidate = -1;
    bool ans = true;
    while(i <= j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }else{
            // cout << arr[i] << " != " << arr[j] << endl;
            ans = isPalindrome(arr, arr[i]) || isPalindrome(arr, arr[j]);
            break;
        }
    }
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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