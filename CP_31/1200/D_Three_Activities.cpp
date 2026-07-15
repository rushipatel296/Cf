#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

// int dp[100005][2][2][2];

// int helper(vector<int>& a, vector<int>& b, vector<int>& c, bool ski_done, bool movie_done, bool board_done, int day, vector<vector<vector<vector<int>>>>& dp){
//     if (ski_done && movie_done && board_done) {
//         return 0; // Success!
//     }
//     if (day >= a.size()) {
//         return 0; // Invalid path, heavily penalize it
//     }
//     if(dp[day][ski_done][movie_done][board_done] != -1){
//         return dp[day][ski_done][movie_done][board_done];
//     }
//     //on the current day we have 4 options
//     int option1 = helper(a, b, c, ski_done, movie_done, board_done, day + 1, dp); //do nothing
    
//     int option2 = INT_MIN;
//     int option3 = INT_MIN;
//     int option4 = INT_MIN;
//     // if ski is not done, go skiing
//     if(!ski_done){  
//         option2 = a[day] + helper(a, b, c, true, movie_done, board_done, day + 1, dp);
//     }
//     // if movie is not done, go movie
//     if(!movie_done){  
//         option3 = b[day] + helper(a, b, c, ski_done, true, board_done, day + 1, dp);
//     }
//     // if board games is not done, do board games
//     if(!board_done){  
//         option4 = c[day] + helper(a, b, c, ski_done, movie_done, true, day + 1, dp);
//     }
//     return dp[day][ski_done][movie_done][board_done] = max(option1, max(option2, max(option3, option4)));
// }   

// void solve(){
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     vector<int> b(n);
//     vector<int> c(n);


//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> b[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> c[i];
//     }
//     //DP dimensions : n x 2 x 2 x 2
    
//     memset(dp, 0, sizeof(dp));

//     for(int day = n - 1; day >= 0; day--){
//         for(int ski_done = 1; ski_done >= 0; ski_done--){
//             for(int movie_done = 1; movie_done >= 0; movie_done--){
//                 for(int board_done = 1; board_done >= 0; board_done--){
//                     if (ski_done && movie_done && board_done) {
//                         dp[day][ski_done][movie_done][board_done] = 0;
//                         continue;;
//                     }
//                     if (day >= a.size()) {
//                         dp[day][ski_done][movie_done][board_done] = 0;
//                         continue;;
//                     }

//                     //on the current day we have 4 options
//                     int option1 = dp[day + 1][ski_done][movie_done][board_done]; //do nothing
                    
//                     int option2 = INT_MIN;
//                     int option3 = INT_MIN;
//                     int option4 = INT_MIN;
//                     // if ski is not done, go skiing
//                     if(!ski_done){  
//                         option2 = a[day] + dp[day + 1][1][movie_done][board_done];
//                     }
//                     // if movie is not done, go movie
//                     if(!movie_done){  
//                         option3 = b[day] + dp[day + 1][ski_done][1][board_done];
//                     }
//                     // if board games is not done, do board games
//                     if(!board_done){  
//                         option4 = c[day] + dp[day + 1][ski_done][movie_done][1];
//                     }
//                     dp[day][ski_done][movie_done][board_done] = max(option1, max(option2, max(option3, option4)));
//                 }
//             }
//         }
//     }
//     // vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
//     cout << dp[0][0][0][0] << endl;
    
// }

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    // Allocates EXACTLY enough memory for this testcase (O(N) time to create)
    // Initializes everything to -1e9 (Invalid path)
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1e9))));

    // Base case: If we finish all 3 activities, no more friends needed (cost 0)
    for(int day = 0; day <= n; day++){
        dp[day][1][1][1] = 0;
    }

    for(int day = n - 1; day >= 0; day--){
        for(int ski_done = 1; ski_done >= 0; ski_done--){
            for(int movie_done = 1; movie_done >= 0; movie_done--){
                for(int board_done = 1; board_done >= 0; board_done--){
                    
                    if (ski_done && movie_done && board_done) continue;

                    int option1 = dp[day + 1][ski_done][movie_done][board_done]; 
                    
                    int option2 = -1e9, option3 = -1e9, option4 = -1e9;
                    
                    if(!ski_done)   option2 = a[day] + dp[day + 1][1][movie_done][board_done];
                    if(!movie_done) option3 = b[day] + dp[day + 1][ski_done][1][board_done];
                    if(!board_done) option4 = c[day] + dp[day + 1][ski_done][movie_done][1];
                    
                    dp[day][ski_done][movie_done][board_done] = max({option1, option2, option3, option4});
                }
            }
        }
    }
    
    cout << dp[0][0][0][0] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}