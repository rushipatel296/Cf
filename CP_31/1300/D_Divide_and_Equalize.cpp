#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;
// vector<bool> isPrime;

// vector<bool> find_primes(int n){
//     vector<bool> isPrime(n + 1, true);
//     isPrime[1] = false;
//     for(int i = 2; i <= n; i++){
//         if(isPrime[i] == true){
//             for(int f = 2; i * f <= n; f++){
//                 isPrime[i * f] = false;
//             }
//         }
//     }
//     return isPrime;
// }

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    // int largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        // largest = max(largest, arr[i]);
    }

    //find all primes from 2 -> largest;

    bool ans = true;
    map<int, int> prime_freq;
    for(int i = 0; i < n; i++){
        int ele = arr[i];
        for(int p = 2; p * p <= ele; p++){
            int cur_freq = 0;
            while(ele % p == 0){
                cur_freq++;
                ele = ele / p;
            }
            prime_freq[p] += cur_freq;
        }
        if(ele > 1){
            prime_freq[ele]++;
        }
    }

    for(auto [prime, freq] : prime_freq){
        if(freq % n != 0){
            ans = false;
            break;
        }
    }
    // for(int i = 2; i <= largest; i++){
    //     if(isPrime[i]){
    //         int pow = 0;
    //         for(int ele : arr){
    //             while(ele % i == 0){
    //                 ele = ele / i;
    //                 pow++;
    //             }
    //         }

    //         if(pow % n != 0){
    //             ans = false;
    //             break;
    //         }
    //     }
    // }

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    //for each prime, check if that prime divides each element 


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // isPrime = find_primes(1e6);
    cin >> t;
    while(t--)
        solve();
}