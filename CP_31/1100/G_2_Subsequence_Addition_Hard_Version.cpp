#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

// bool checker(vector<int>& c, int index){
//     if(index >= c.size()) return true;

//     if(checker(c, index + 1) == false){
//         return false;
//     }
//     int target = c[index];

//     for(int i = index + 1; i < c.size(); i++){
//         // there are two options at index + 1 either include or exclude

//         //include 
//         int sum_so_far = index + 1 < n ? c[index + 1] : 0;
        
//     }

// }

void solve(){
    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }


    sort(all(c));
    bool possible = true;
    if(c[0] != 1){
        possible = false;
    }
    ll sum = 1;

    for(int i = 1; i < n; i++){
        if(c[i] > sum){
            possible = false;
            break;
        }else{
            sum += c[i];
        }
    }

    if(possible){
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