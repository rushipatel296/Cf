#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string n;
    cin >> n;

    ll num = 0;
    int mini = n.size();

    for(int i = n.size() - 1; i >= 0; i--){
        if(n[i] == '5'){
            //find a 7 or a 2
            int j = i - 1;
            while(j >= 0 && (n[j] != '2' && n[j] != '7')){
                j--;
            }

            if(j >= 0){
                //we found a 7 or 2 at j and a 5 at i
                // cout << j << "th index : " << n[j] << " ,"<< i << "th index : " << n[i] << endl;
                int removals = (n.size() - i - 1) + (i - j - 1);
                // cout << "removal of trailing digits + intermediate digits : " << removals << endl;
                mini = min(mini, removals);
            }

        }else if(n[i] == '0'){
            int j = i - 1;
            while(j >= 0 && (n[j] != '5' && n[j] != '0')){
                j--;
            }

            if(j >= 0){
                //we found a 7 or 2 at j and a 5 at i
                // cout << j << "th index : " << n[j] << " ,"<< i << "th index : " << n[i] << endl;
                int removals = (n.size() - i - 1) + (i - j - 1);
                // cout << "removal of trailing digits + intermediate digits : " << removals << endl;
                mini = min(mini, removals);
            }
        }
    }
    cout << mini << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}