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

// void solve(){
//     ll n;
//     cin >> n;

//     // n++; //from 0 to n

//     ll ans = 0;
//     ll rem = n / 4;
//     debug(rem);
//     ans += (n / 4) * 4;
//     cout << "Ans after adding 3 for every group of 4 : " << ans << endl;
//     ll groups = (n / 4);
//     ll transitions = groups - 1 + ((rem > 0) ? 1 : 0);

//     cout << "Groups of 4 : " << groups << " transitions : " << transitions << endl;
//     ll factor = 2;
//     ans += transitions * 3; //after every group of 4, at min, there are 3 bit flips
//     cout << "Ans after adding 3 for every transition between groups of 4 : " << ans << endl;
//     groups = n / (factor * 4);

//     while(groups > 0){
//         transitions = groups - 1 + ((rem > 0) ? 1 : 0);
//         ans += transitions;

//         factor++;
//         groups = n / (factor * 4);
//     }

//     cout << ans << endl;
// }

void solve(){
    ll n;
    cin >> n;

    ll ans = 0;

    // We will repeatedly process the number by breaking it into groups of 4
    while (n > 0) {
        ll groups = n / 4;
        ll rem = n % 4; // Use modulo to correctly find the remainder, not division!

        // 1. Internal transitions in a group of 4 sum to 4 flips (1 + 2 + 1).
        // 2. The boundary transition adds a base of 2 flips (plus recursive flips handled in the next loop).
        // Total fixed contribution per group of 4 is 4 + 2 = 6.
        ans += groups * 6;

        // 3. Add the specific flips for the remainder transitions at the end
        if (rem == 1) ans += 1;
        else if (rem == 2) ans += 3; // (0->1) + (1->2) = 1 + 2
        else if (rem == 3) ans += 4; // (0->1) + (1->2) + (2->3) = 1 + 2 + 1

        // 4. Because boundary transitions mirror the exact same problem divided by 4,
        // we just push the number of groups back into n and repeat!
        n = groups;
    }

    cout << ans << endl;
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