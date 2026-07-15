#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int a, b;
    cin >> a >> b;

    int arr_size = a;
    
    int num = a - 1; // 0 -> a-1 : a nums in the array present
    int x = 0;

    int carry = a % 4;
    while(carry){
        x = x ^ num;
        num--;
        carry--;
    }

    if(x != b){
        int target = b ^ x;
        if(target == a){
            arr_size += 2;
        }else{
            arr_size++;
        }
    }

    cout << arr_size << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}