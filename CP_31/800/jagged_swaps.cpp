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
#include <climits>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define mp make_pair
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

bool isSorted(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i - 1] >= arr[i])return false;
    }
    return true;
}

void solve() {
    // Write your solution here
    int n;
    cin >> n;
    vi arr;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr.pb(k);
    }
    
    if(arr[0] == 1) {
        cout << "YES" << endl;
    } else {
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