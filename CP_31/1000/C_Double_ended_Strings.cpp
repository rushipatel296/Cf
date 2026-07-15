#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string a, b;
    cin >> a >> b;

    int ops = a.size() + b.size();

    for(int i = 0; i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            int size = j - i + 1;
            string substr = a.substr(i, size);
            if(b.find(substr) != string::npos){
                ops = min(ops, (int)(a.size() - size + b.size() - size));
            }
        }
    }

    for(int i = 0; i < b.size(); i++){
        for(int j = i; j < b.size(); j++){
            int size = j - i + 1;
            string substr = b.substr(i, size);
            if(a.find(substr) != string::npos){
                ops = min(ops, (int)(a.size() - size + b.size() - size));
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