#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;


void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, vector<int>> mpp;  //group the numbers based on mod y
    
    for(int i = 0; i < n; i++){
        mpp[arr[i] % y].push_back(arr[i]);
    }
    ll count = 0;
    for(auto it : mpp){
        // int rem = it.first;
        vector<int> v = it.second; //elements having rem 
        map<int, int> m1;
        for(size_t i = 0; i < v.size(); i++){
            m1[v[i] % x]++;
        }

        for(auto it : m1){
            int freq = it.second;
            int r = it.first;

            if(r == 0 || (r == (x / 2) && x % 2 == 0)){
                count += (1LL * freq * (freq - 1)) / 2; // case where we make pairs from the same group
            }else{
                // remainder need to sum up to x
                int f2 = m1[x - r];
                count += freq * f2;
                m1[x - r] = 0; // so that pairs are not counted twice

            }
        }
    }

    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}