#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n, m;

    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(all(a));
    vector<int> v;
    for(int i = 1; i < m; i++){
        int d = a[i] - a[i - 1] - 1;
        v.push_back(d);
    }
    int rotate = (n - a[m - 1]) + (a[0] - 1);
    v.push_back(rotate);
    sort(v.rbegin(), v.rend());

    // for(auto ele : v){
    //     cout << ele << " ";
    // }
    // cout << endl;

    int day = 0;
    int i = 0;
    int size = v.size();
    int protect = 0;
    while(i < size){
        int diff = v[i];
        // cout << "Day : " << day << endl;
        
        diff = max(diff - (2 * day), 0);
        // cout << i + 1 << " ele : " << diff << endl;
        if(diff == 0){
            break;
        }
        if(diff == 1 || diff == 2){
            // cout << "Adding 1 to protected count" << endl;
            protect += 1;
            day++;
        }else{
            // cout << "Adding "<< diff - 1 << " to protected count" << endl;
            protect += diff - 1;
            day += 2;
        }
        i++;
    }
    cout << n - protect << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}