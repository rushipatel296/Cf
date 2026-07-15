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

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define endl '\n'

void solve() {
    // Write your solution here
    int n ;
    cin >> n;
    int lowest = INT_MAX;
    for(int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        lowest = min(lowest, abs(cur));
    }
    cout << lowest << endl;
}

int main() {
    fast_io;
    solve();

    return 0;
}