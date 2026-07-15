#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define endl "\n"

const ll INF = 1e18;
const int MOD = 1e9+7;

// void solve(){
//     int n, k;
//     cin >> n >> k;

//     vector<int> temp(n);
//     for(int i = 0; i < n; i++){
//         cin >> temp[i];
//     }

//     vector<pair<int, int>> arr;

//     for(int i = 0; i < n; i++) arr.push_back(temp, i);

//     sort(all(arr));

//     vector<pair<int, int>> max_jump(k + 1);

//     for(int i = 1; i < n; i++){
//         int prev_colour = temp[i - 1].first;
//         int prev_index = temp[i - 1].second;
//         int colour = temp[i].first;
//         int index = temp[i].second;

//         if(colour != prev_colour){
//             int last_jump = n - prev_index;
//             //handle the last colour's last jump
//             if(max_jump[prev_colour].first < last_jump){
//                 max_jump[prev_colour].first = last_jump;
//                 max_jump[prev_colour].second = 1; // freq of max jump
//             }else if(max_jump[prev_colour].first == last_jump){
//                 max_jump[prev_colour].second++;
//             }
//             //handle the new colour's first jump
//             int first_jump = index;
//             max_jump[index].first = first_jump;
//             max_jump[index].second = 1;
//         }else{
//             //case to update max jump of colour for 2 consecutive coloured planks
//             int cur_jump = index - prev_index - 1;
//             if(cur_jump > max_jump[colour].first){
//                 max_jump[colour].first = cur_jump;
//                 max_jump[colour].second = 1;
//             }else if(cur_jump > max_jump[colour].first){
//                 max_jump[colour].second++;
//             }
//         }
//     }

//     //handle last colours
//     int last_colour = temp[n - 1].first;
//     int last_index = temp[n - 1].second;
//     int last_jump = n - last_index;

//     if(max_jump[last_colour].first < last_jump){
//         max_jump[last_colour].first = last_jump;
//         max_jump[last_colour].second = 1; // freq of max jump
//     }else if(max_jump[last_colour].first == last_jump){
//         max_jump[last_colour].second++;
//     }

//     //find the most appropriate colour

//     int target = -1;
//     int min_jump = INT_MAX;
//     for(int i = 1; i < k; i++){
//         int cur_colour = i;
//         int cur_max_jump = max_jump[cur_colour].first;
//         int cur_freq = max_jump[cur_colour].second;

//         if(cur_max_jump < min_jump){
//             min_jump = cur_max_jump;
//             target = cur_colour;
//         }else if(cur_max_jump == min_jump && cur_freq < max_jump[target].second){
//             min_jump = cur_max_jump;
//             target = cur_colour;
//         }
//     }

//     // now we have the target colour
//     int jump = max_jump[target].first;
//     int freq = max_jump[target].second;
//     int cur_jump = 0;
//     int last_step = -1;
//     //repaint the largest jump and see the new largest jump
//     for(int i = 0; i < temp.size(); i++){   
//         if(temp[i] != target){
//             cur_jump++;
//             if(cur_jump == jump){

//             }
//         }
//     }
// }


void solve(){
    int n, k;f
    cin >> n >> k;
    // 1. Store positions of each color
    vector<vector<int>> pos(k + 1);
    for(int i = 1; i <= k; i++) {
        pos[i].push_back(-1); // Starting ground
    }

    for(int i = 0; i < n; i++){
        int color;
        cin >> color;
        pos[color].push_back(i);
    }

    for(int i = 1; i <= k; i++) {
        pos[i].push_back(n); // Ending ground
    }

    int ans = 1e9; // Start with a large number

    // 2. Process each color
    for(int i = 1; i <= k; i++){
        if(pos[i].size() <= 2) continue; // Color doesn't exist on the bridge

        int l1 = 0, l2 = 0; // l1 = largest, l2 = second largest
        
        // Calculate gaps
        for(int j = 1; j < pos[i].size(); j++){
            int jump = pos[i][j] - pos[i][j-1] - 1;
            
            // Update top 2 jumps
            if(jump >= l1){
                l2 = l1;
                l1 = jump;
            } else if(jump > l2){
                l2 = jump;
            }
        }
        
        // 3. The best we can do for this color is max(l1 / 2, l2)
        int best_for_this_color = max(l1 / 2, l2);
        ans = min(ans, best_for_this_color);
    }

    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}