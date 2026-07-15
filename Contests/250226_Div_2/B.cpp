#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    ll n;
    cin >> n;

    vector<int> freq(10, 0);

    ll temp = n;
    int num_digs = 0;
    while(temp > 0){
        num_digs++;
        int dig = temp % 10;
        freq[dig]++;
        temp = temp / 10;
    }

    int unchanged_digs = 0;
    int dig_sum = 0;
    
    for(int i = 1; i <= 9; i++){
        if((freq[i] * i) + dig_sum <= 9){
            dig_sum += freq[i] * i;
            unchanged_digs += freq[i];
        }else{
            int f = (9 - dig_sum) / i;
            dig_sum += f * i;
            unchanged_digs += f;
            break;
        }
    }
    if(num_digs - unchanged_digs == 1 && dig_sum == 9){
        // cout << "Edge case hit" << endl;
        //one digit needs to be changed to 0 -> that digit can not be the first digit. Add a check for that
        temp = n;
        int itr = 0;
        int dig_sum = 0;
        while(itr < num_digs - 1){
            // cout << "Adding " << temp % 10 << endl;
            dig_sum += temp % 10;
            temp = temp / 10;
            itr++;
        }
        // cout <<  "Sum of last n - 1 digits "<<dig_sum << endl;
        if(dig_sum == 9){
            //case where we need to change the first digit to 0
            cout << 2 << endl; 
            return;
        }
    }
    cout << num_digs - unchanged_digs << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}