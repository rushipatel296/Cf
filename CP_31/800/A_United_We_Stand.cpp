#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    // Your solution logic here
    int n;
    cin >> n;
    vector<int> a, b, c;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        a.push_back(ele);
    }
    sort(a.begin(), a.end());
    for(int i = 0 ; i < a.size(); i++){
        if(b.empty() && c.empty()){
            b.push_back(a[i]);
        }else{
            int cur = a[i];
            bool inB = false;
            for(int j = 0; j < b.size(); j++){
                if(b[j] % cur == 0){
                    //current element divides some element of b
                    b.push_back(cur);
                    inB = true;
                    break;
                } 
            }
            if(!inB){
                c.push_back(cur);
            }
        }
    }

    if(c.empty()){
        cout << "-1" << endl;
    } else{
        cout << b.size() << " " << c.size() << endl;
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < c.size(); i++){
            cout << c[i] << " ";
        }
        cout << endl;
    }
    


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}