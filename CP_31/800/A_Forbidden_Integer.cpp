#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <climits>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if(x != 1){
        cout << "YES" << endl;
        cout << n << endl;
        while(n--){
            cout << "1" << " ";
        }
        cout << endl;
        return;
    }
    // forbidden integer is 1
    //
    // 2 possibilities -> n is odd or even
    //n : odd
    if(n % 2 == 1){
        // one of the ints would be the biggest odd integer in 1->k followed by remaining 2s

        int biggest_odd = INT_MIN;
        for(int i = k; i >= 3; i--){
            if(i % 2 == 1){
                biggest_odd = i;
                break;
            }
        }
        if(biggest_odd != INT_MIN){
            cout << "YES" << endl;
            cout << 1 + (n - biggest_odd) / 2 << endl;
            cout << biggest_odd << " ";
            n = n - biggest_odd;
            while(n > 0){
                cout << "2" << " ";
                n = n - 2;
            }
            cout << endl;
            return;
        }else { 
            cout << "NO" << endl;
            return;
        }
    }else{
        if(k >= 2){
            cout << "YES" << endl;
            cout << (n / 2) << endl;
            while(n > 0){
                cout << "2" << " ";
                n = n - 2;
            }
            cout << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
        
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}