#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

vector<int> factors(int n){
    vector<int> ans;
    ans.push_back(1);

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    ans.push_back(n);
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> cnt(n + m + 1, 0);

    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    vector<ll> c(n + m + 1); 
    for(ll i = 1; i <= n + m; i++){
        for(ll j = 1; i * j <= n + m; j++){
            c[i * j] += cnt[i];
        }
    }  
    int A = 0;
    int B = 0;
    int C = 0;

    for(int i = 0; i < m; i++){
        ll freq = c[b[i]];

        if(freq == n){
            A++;
        }else if(freq == 0){
            B++;
        }else{
            C++;
        }
    }

    if(C % 2 == 0){
        //A starts 
        if(A > B){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }else{
        if(B > A){
            cout << "Bob" << endl;
        }else{
            cout << "Alice" << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}