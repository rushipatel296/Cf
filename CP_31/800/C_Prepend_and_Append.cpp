#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    string s;
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        s.push_back(ch);
    }


    int i = 0;
    int j = s.size() - 1;

    while(i < j){
        if((s[i] == '1' && s[j] == '0') || (s[i]== '0' && s[j] == '1')){
            i++;
            j--;
        }else{
            break;
        }
    }

    int len =  j - i + 1;
    cout << len << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}