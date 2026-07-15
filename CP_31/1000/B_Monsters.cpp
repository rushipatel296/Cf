#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

// struct cmp {
//     bool operator() (const pair<int, int>& a, const pair<int, int>& b){
//         if(a.first != b.first){
//             return !(a.first < b.first);
//         }
//         return !(a.second < b.second);
//     }
// };

bool cmp (const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}


void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++){
        vec.push_back({((arr[i] % k) == 0 ? k : (arr[i] % k)), i});
    }

    sort(all(vec), cmp);

    for(auto it : vec){
        cout << it.second + 1 << " ";
    }
    cout << endl;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    // //pair would be (hp, index)

    // for(int i = 0; i < n; i++){
    //     pq.push({arr[i], i});
    // }
    // vector<int> order;
    // while(!pq.empty()){
    //     auto top = pq.top();
    //     int highest_hp = top.first;
    //     int idx = top.second;

    //     highest_hp -= k;
    //     if(highest_hp <= 0){
    //         order.push_back(idx);
    //         pq.pop();
    //     }else{
    //         pq.pop();
    //         pq.push({highest_hp, idx});
    //     }
    // }

    // for(int i = 0; i < order.size(); i++){
    //     cout << order[i] + 1<< " ";
    // }
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}