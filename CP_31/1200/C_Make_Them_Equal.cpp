#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;
// const int tot = 3e5 + 1;

// vector<bool> primes(tot, true);

void solve(){
    int n;
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    bool all_match = true;
    for(int i = 0; i < n; i++){
        if(s[i] != c){
            all_match = false;
            break;
        }
    }
    //case 0
    if(all_match){
        cout << 0 << endl;
        return;
    }

    //case 1 
    for(int x = 1; x <= n; x++){
        bool possible = true;

        for(int j = x; j <= n; j += x){
            if(s[j - 1] != c){
                possible = false;
                break;
            }
        }

        if(possible){
            cout << 1 << endl << x << endl;
            return;
        }
    }

    //case 2 
    cout << 2 << endl << n << " " << n - 1 << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    
    
    // primes[0] = false;
    // primes[1] = false;

    // for(int p = 2; p * p <= tot; p++){
    //     if(primes[p] == true){
    //         for(int j = p; p * j <= tot; j++){
    //             primes[p * j] = false;
    //         }
    //     }
    // }

    // we have all primes <= 3 * 10^ 5
    while(t--)
        solve();
}