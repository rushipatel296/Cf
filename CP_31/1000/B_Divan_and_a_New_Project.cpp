#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    //(freq, idx)
    //higher freq should come first 
    if(a.first != b.first){
        return a.first > b.first;
    }

    // for same freq, lower index
    return a.second < b.second;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> f(n);
    for(int i = 0; i < n; i++){
        int freq;
        cin >> freq;
        f[i] = {freq, i + 1};
    }
    // sort(f.rbegin(), f.rend());
    sort(f.begin(), f.end(), cmp);


    vector<int> ans(n + 1);

    ans[0] = 0;
    ll dist = 0; 
    ll c = 1;
    bool plus = true;
    for(auto ele : f){
        int freq = ele.first;
        int idx = ele.second;

        if(plus){
            ans[idx] = c;
            dist += 2LL * abs(c) * freq;
        }else{
            ans[idx] = -c;
            dist += 2LL * abs(c) * freq;
            c++;
        }
        plus = !plus;
    }   
    cout << dist << endl;
    for(auto ele : ans){
        cout << ele << " ";
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}