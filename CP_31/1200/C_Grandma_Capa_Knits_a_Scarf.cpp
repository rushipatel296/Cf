#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

int isPalindrome(string& s, char candidate){
    int n = s.size();

    int i = 0;
    int j = n - 1;
    bool ans = true;
    int ops = 0;

    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            if(s[i] == candidate){
                i++;
                ops++;
            }else if(s[j] == candidate){
                j--;
                ops++;
            }else{
                ans = false;
                break;
            }
        }
    }

    if(ans){
        return ops;
    }
    return INT_MAX;
    // cout << "Ignoring " << candidate << ", Result : " << ans << endl;
    // return ans;

}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = 0;
    int j = n - 1;
    int ans = 0;
    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else{
            // cout << s[i] << " != " << s[j] << endl;
            ans = min(isPalindrome(s, s[i]), isPalindrome(s, s[j]));
            break;
        }
    }
    if(ans != INT_MAX){
        cout << ans << endl;
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