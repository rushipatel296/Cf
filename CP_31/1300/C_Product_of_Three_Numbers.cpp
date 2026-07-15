#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9 + 7;

// --- DEBUG TEMPLATE BEGIN ---
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// --- DEBUG TEMPLATE END ---

map<int, int> factorize(int n){
    map<int, int> freq;

    while(n % 2 == 0){
        freq[2]++;
        n = n / 2;
    }

    for(int i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            freq[i]++;
            n = n / i;
        }
    }

    if(n > 1){
        freq[n]++;
    }

    return freq;

}

void solve(){
    int n;
    cin >> n;

    map<int, int> powers_of = factorize(n);
    debug(powers_of);
    bool possible = true;
    if(powers_of.size() == 1){
        for(auto [prime, power] : powers_of){
            if(power <= 5){
                possible = false;
            }else{
                cout << "YES" << endl;
                cout << prime << " " << (prime * prime) << " " << n / (prime * prime * prime) << endl;
            }
        }
    } else if(powers_of.size() == 2){
        int p1 = -1, p2 = -1, pow1 = -1, pow2 = -1; 
        for(auto [prime, power] : powers_of){
            if(p1 == -1){
                p1 = prime;
                pow1 = power;
            }else{
                p2 = prime;
                pow2 = power;
            }
        }

        if(pow1 + pow2 <= 3){
            possible = false;
        }else{
            cout << "YES" << endl;
            if(pow1 == 1){
                cout << p1 << " " << p2 << " " << n / (p1 * p2) << endl;
            }else if(pow2 == 1){
                cout << p2 << " " << p1 << " " << n / (p1 * p2) << endl;
            }else{
                cout << p1 << " " << p2 << " " << n / (p1 * p2) << endl;
            }
        }
    }else{
        // more than 3 primes
        int p1 = -1, p2 = -1; 
        for(auto [prime, power] : powers_of){
            if(p1 == -1){
                p1 = prime;
                // pow1 = power;
            }else{
                p2 = prime;
                // pow2 = power;
                break;
            }
        }
        cout << "YES" << endl;
        cout << p1 << " " << p2 << " " << n / (p1 * p2) << endl;
    }
    
    if(!possible){
        cout << "NO" << endl;
    }


}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}