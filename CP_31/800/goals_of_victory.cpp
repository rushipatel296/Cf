#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        int ele;
        cin >> ele;

        sum += ele;
    }
    sum = -1 * sum;
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}