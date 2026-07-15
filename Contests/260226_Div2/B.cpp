#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

vector<ll> getUniquePrimeFactors(ll n) {
    vector<ll> primeFactors;

    // Handle factor 2 separately to optimize the loop
    if (n % 2 == 0) {
        primeFactors.push_back(2);
        while (n % 2 == 0) {
            n /= 2; // Divide n until it's no longer divisible by 2
        }
    }

    // Check for odd factors from 3 up to the square root of n
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            primeFactors.push_back(i);
            while (n % i == 0) {
                n /= i; // Divide n until it's no longer divisible by i
            }
        }
    }

    // If n is a prime number greater than 2 at this point, add it to the list
    if (n > 2) {
        primeFactors.push_back(n);
    }

    return primeFactors;
}

void solve(){
    ll n;
    cin >> n;

    vector<ll> primes = getUniquePrimeFactors(n);

    ll ans = 1;
    for(int i = 0; i < primes.size(); i++){
        ans = ans * primes[i];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}