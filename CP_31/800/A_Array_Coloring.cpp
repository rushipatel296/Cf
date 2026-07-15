#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    // Write your solution here
    int n;
    cin >> n;
    int odd_count = 0;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        if(ele % 2 == 1) odd_count++;

    }
    if(odd_count % 2 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}