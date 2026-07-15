#include <bits/stdc++.h>
using namespace std;

int solve(int l, int a, int b){
    unordered_map<int, int> count;
    count[a]++;
    int ans = a;
    int next = (a + b) % l;
    while(count[next] < 1){
        count[next]++;
        ans = max(ans, next);
        next = (next + b) % l;
    }
    return ans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int l, a, b;
        cin >> l >> a >> b;
        cout << solve(l, a, b) << endl;
    }
}