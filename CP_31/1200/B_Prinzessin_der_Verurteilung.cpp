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
    string s; 
    cin >> s;
    string mex = "";
    for(int i = 0; i < 26; i++){
        if(s.find(i + 'a') == string::npos){
            mex = i + 'a';
            break;
        }
    }

    if(mex != ""){
        cout << mex << endl;
        return;
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            string cur = "";
            cur.push_back(i + 'a');
            cur.push_back(j + 'a');
            if(mex == "" && s.find(cur) == string::npos){
                mex = cur;
                break;
            }
        }
    }
    if(mex != ""){
        cout << mex << endl;
        return;
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                string cur = "";
                cur.push_back(i + 'a');
                cur.push_back(j + 'a');
                cur.push_back(k + 'a');
                if(mex == "" && s.find(cur) == string::npos){
                    mex = cur;
                }
            }
        }
    }
    cout << mex << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}