#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    string s ;
    cin >> s;

    // for(int i = 0; i < n; i++){
    //     int j = i + 1;
    //     int itr = i;
    //     if(s[i] == s[j] && s[i] != '*'){
    //         s[i] = '*';
    //         s[j] = '*';

            
    //         while(s[i] == '*' && i - 1 > 0){
    //             i--;
    //         }
    //         while(s[j] == '*' && j + 1 < n){
    //             j++;
    //         }
    //         while(i >= 0 && j < n && s[i] == s[j]){
    //             s[i] = '*';
    //             s[j] = '*';
    //             i--;
    //             j++;
    //         }
            
    //     }
    //     i = itr;
    // }

    for(int i = 0; i < n; i++){
        int start = i;
        int end = i + 1;
        // cout << " i : " << i << " start : " << start << " end : " << end << endl;

        while(s[start] == '*' && start - 1 >= 0){
            // cout << "start is a * -> decrementing start : " <<  start - 1 << endl;
            start--;
        }
        while(s[end] == '*' && end + 1 < n){
            // cout << "end is a * -> incrementing end : " << end + 1 << endl;

            end++;
        }

        while(start >= 0 && end < n && s[start] == s[end]){
            // cout << start <<" and "<< end << " are equal -> turning to start and expanding window" << endl;
            
            s[start] = '*';
            s[end] = '*';
            // cout << "debug string now : " << s <<endl;
            while(s[start] == '*' && start - 1 >= 0){
                // cout << "start is a * -> decrementing start : " <<  start - 1 << endl;
                start--;
            }
            end++;
        }

    }

    int flag = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '*'){
            flag = 1;
            break;
        }
    }
    // cout << "DEBUG String : " << s << endl;
    if(flag){
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