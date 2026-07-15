#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

void operate_arr(vector<int>& arr, int index){
    int n = arr.size();
    int ele = arr[index];
    for(int i = index; i < arr.size() - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = ele;
    return;
}

void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve(){
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    k--;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cost_so_far = 0;
    int count = 0;
    // cout << "Debug array : " << endl;
    // print(arr);

    while(cost_so_far < m){
        

        if(p <= k){
            if(cost_so_far + arr[p] <= m){
                // cout << arr[p] << " is in the first k : " << k + 1 << " indexes, playing it." << endl;
                cost_so_far += arr[p];
                // cout << "cost : " << cost_so_far << endl;
                operate_arr(arr, p);
                // cout << "Shifting after playing p to the last : " << endl;
                // print(arr);
                p = n - 1;
                count++;
            }else{
                break;
            }
        }else{
            //find the cheapest move
            // cout << "Currently p is at : " << p << "th index, playing the smallest card from first " << k + 1 << " cards" << endl;
            int cheapest = INT_MAX;
            int cheap_idx = -1;
            for(int i = 0; i <= k; i++){
                if(arr[i] < cheapest){
                    cheapest = arr[i];
                    cheap_idx = i;
                }
            }
            if(cost_so_far + cheapest <= m){
                // cout <<"Playing card at " << cheap_idx << " index : " << cheapest << endl;
                cost_so_far += cheapest;
                operate_arr(arr, cheap_idx);
                p--;
                // cout << "Array after playing cheapest card :" << endl;
                // cout << "cost : " << cost_so_far << endl;
                // print(arr);
                // cout << "position of p : " << p << endl;
            }else{
                break;
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