#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;
void clean_up(vector<vector<int>>& lst, unordered_set<int>& seen){
    for(int i = 0; i < lst.size(); i++){
        vector<int> new_cur; 
        for(int j = 0; j < lst[i].size(); j++){
            if(seen.find(lst[i][j]) == seen.end()){
                new_cur.push_back(lst[i][j]);
            }
        }
        lst[i] = new_cur; 
    }
    sort(lst.begin(), lst.end()); 
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> lst(n);
    int idx = 0;
    
    // Store original n for the loop to avoid messing up lst initialization
    int original_n = n; 
    while(original_n--){
        int size;
        cin >> size;
        vector<int> l(size);
        for(int i = 0; i < size; i++){
            cin >> l[i];
        }

        reverse(l.begin(), l.end());

        unordered_set<int> seen;
        vector<int> m;
        for(int i = 0; i < l.size(); i++){
            if(seen.find(l[i]) == seen.end()){
                m.push_back(l[i]);
                seen.insert(l[i]);
            }
        }
        lst[idx] = m;
        idx++;
    }
    
    sort(lst.begin(), lst.end());
    unordered_set<int> seen;
    vector<int> ans;
    

    while(!lst.empty()){
        vector<int> k = lst[0];
        lst.erase(lst.begin()); 
        
        for(int j = 0; j < k.size(); j++){
            if(seen.find(k[j]) == seen.end()){
                ans.push_back(k[j]);
                seen.insert(k[j]);
            }
        }

        clean_up(lst, seen); 
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}