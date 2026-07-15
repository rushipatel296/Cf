#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int target = 0;
    for(int i = 0; i < 10; i++){
        vector<char> row(10);
        for(int j = 0; j < 10; j++) {
            char ch ;
            cin >> ch;
            row[j] = ch;
        }
        if(i == 0 || i == 9){
            for(int j = 0; j < 10; j++){
                if(row[j] == 'X') target = target + 1;
            }
        }else if(i == 1 || i == 8){
            for(int j = 0; j < 10; j++){
                if(row[j] == 'X'){
                    if(j == 0 || j == 9){
                        target += 1;
                    }else{
                        target += 2;
                    }
                }
            }
        }else if(i == 2 || i == 7){
            for(int j = 0; j < 10; j++){
                if(row[j] == 'X'){
                    if(j == 0 || j == 9){
                        target += 1;
                    }else if(j == 1 || j == 8){
                        target += 2;
                    }else{
                        target += 3;
                    }
                }
            }
        }else if(i == 3 || i == 6){
            for(int j = 0; j < 10; j++){
                if(row[j] == 'X'){
                    if(j == 0 || j == 9){
                        target += 1;
                    }else if(j == 1 || j == 8){
                        target += 2;
                    }else if(j == 2 || j == 7){
                        target += 3;
                    }else { 
                        target += 4;
                    }
                }
            }
        }else{  // i == 4 || i == 5
            for(int j = 0; j < 10; j++){
                if(row[j] == 'X'){
                    if(j == 0 || j == 9){
                        target += 1;
                    }else if(j == 1 || j == 8){
                        target += 2;
                    }else if(j == 2 || j == 7){
                        target += 3;
                    }else if(j == 3 || j == 6){ 
                        target += 4;
                    }else {
                        target += 5;
                    }
                }
            }
        }
    }
    cout << target << endl;
    return;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}