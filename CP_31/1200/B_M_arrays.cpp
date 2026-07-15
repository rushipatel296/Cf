#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];


    vector<int> freq(m, 0);
    for(int i = 0; i < n; i++){
        int a = arr[i] % m;
        freq[a]++;
    }
    int count = 0;
    if(freq[0] > 0){
        count++;
    }

    for(int i = 1; i <= (m / 2); i++){
        int f1 = freq[i];
        int f2 = freq[m - i];
        // cout << "i = " << i << " freq[i] = " << f1 << endl;
        // cout << "m - i = " << m - i << " freq[m - i] = " << f2 << endl;
        if(f1 == 0 && f2 == 0) continue;
        if(i == m - i){
            count++;
        }
        else {
            if(abs(f1 - f2) <= 1){
                count++;
            } else {
                // 1 array for the alternating part + individual arrays for the leftovers
                // The math neatly simplifies to the absolute difference
                count += abs(f1 - f2);
            }
        }
    }

    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}