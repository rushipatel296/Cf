// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// #define all(x) (x).begin(), (x).end()
// #define endl "\n"

// const ll INF = 1e18;
// const int MOD = 1e9+7;

// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     vector<int> arr(n);

//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     vector<int> middle(y - x);
//     vector<int> ends(n - y + x);
//     int smallest_mid = INT_MAX;
//     int smallest_mid_idx = -1;
//     for(int i = x; i <= y - 1; i++){
//         if(arr[i] < smallest_mid){
//             smallest_mid = arr[i];
//             smallest_mid_idx = i;
//         }
//     }
//     vector<int> ans(n);
//     int k = 0;
//     for(int i = x; i <= y - 1; i++){
//         if(smallest_mid_idx + i <= y - 1){
//             middle[k] = arr[smallest_mid_idx + i];
//         }else{
//             int idx = smallest_mid + i - y + x;
//             middle[k] = arr[idx];
//         }
//         k++;
//     }
//     int i = 0;
//     for(; i <= x - 1; i++){
//         ends[i] = arr[i];
//     }
//     for(int j = y; j <= n - 1; j++){
//         ends[i++] = arr[j];
//     }
//     int b = 0;

//     while(b < ends.size() && ends[b] < middle[0]){
//         b++;
//     }
//     i = 0;
//     for(; i < b; i++){
//         ans[i] = ends[i];
//     }
//     for(int j = 0 ; j < middle.size(); j++){
//         ans[i] = middle[j];
//         i++;
//     }
//     for(int j = b; j < ends.size(); j++){
//         ans[i] = ends[j];
//         i++;
//     }

//     for(int i = 0; i < ans.size(); i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;

// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t = 1;
//     cin >> t;
//     while(t--)
//         solve();
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (i <= x || i > y) a.push_back(j);
        else b.push_back(j);
    }

    // solve
    if (!b.empty()) rotate(b.begin(), min_element(b.begin(), b.end()), b.end());
    int m = b.empty() ? -1 : b[0];
    auto it = a.begin();
    while (it != a.end() && *it < m) it++;
    a.insert(it, b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}