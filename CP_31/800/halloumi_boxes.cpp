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
#define endl '\n'

bool isSorted(vector<int>& arr){
    bool ans = true;
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void solve() {
    // Write your solution logic here
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }

    if(isSorted(arr)) {
        cout << "YES" << endl;
        return;
    }

    //we can reverse at most k sized subarray, can the array be sorted in a non-decreasing order?
    //if k >= 2 -> we can use bubble sort to sort the array - right?

    if(k >= 2){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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