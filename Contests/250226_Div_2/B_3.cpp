#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;
    
    int total_sum = 0;
    for(char c : s) total_sum += c - '0';
    
    if(total_sum <= 9){ cout << 0 << "\n"; return; }
    
    // Collect digits, mark first digit specially
    // We want to keep subset with sum <= 9, maximize kept count
    // Greedily keep smallest digits first
    // But first digit: if we don't keep it, we must change it to 1-9 (not 0)
    // That doesn't affect the "kept" count calculation much
    
    vector<int> digits;
    for(char c : s) digits.push_back(c - '0');
    
    // Try: keep some digits summing to <= 9, change others
    // To maximize kept, sort all digits ascending and keep as many as possible
    // Special case: if first digit is changed, it costs 1 move but can't be 0
    // (but we're counting moves, not what we change to)
    // The constraint is just: result has no leading zeros
    // If we change the first digit, we set it to something nonzero -> fine, 1 move
    // So leading zero constraint doesn't add extra moves, UNLESS all digits are changed to 0
    // which can't happen since first digit must be >= 1
    
    vector<int> sorted_digits = digits;
    sort(sorted_digits.begin(), sorted_digits.end());
    
    int kept = 0, cur_sum = 0;
    for(int d : sorted_digits){
        if(cur_sum + d <= 9){ cur_sum += d; kept++; }
        else break;
    }
    
    int ans = (int)digits.size() - kept;
    
    // Edge case: if kept == size-1 and the one changed digit is the first digit
    // and cur_sum==0, then we'd need first digit to be nonzero -> but cur_sum>0 usually
    // Actually if cur_sum <= 9 and ans>=1, the changed digits become:
    // first digit -> at least 1 (fine), others -> 0 (fine)
    // Only problem: if we keep all digits except first, and cur_sum=9,
    // then changed digit (first) becomes... we need total sum <=9
    // We set first digit to make sum still <=9, e.g., set to 0... but can't!
    // So if kept = n-1 and the unkept digit is the first digit and cur_sum=9,
    // we need first digit=0 which is invalid. Cost becomes 2 instead of 1.
    
    if(ans == 1){
        // Check if the digit we're changing is forced to be the first digit AND must be 0
        // The digit we change is the largest digit
        // cur_sum = sum of all except largest
        // If largest digit is at position 0 (first), we'd set it to 0 -> invalid
        // But we could instead change a different digit
        // If cur_sum <= 9 already without the largest, check if largest is first digit
        int largest = sorted_digits.back();
        // sum without largest = total_sum - largest
        int remaining = total_sum - largest;
        if(remaining <= 9){
            // We change the largest digit. Is it necessarily the first digit?
            // Only a problem if first digit == largest AND all other occurrences of 'largest' 
            // are also needed... actually we just need to check:
            // can we find ONE digit (not first) to change to make sum <= 9?
            // i.e., is there a non-first digit >= (total_sum - 9)?
            int need_to_remove = total_sum - 9; // minimum we need to subtract
            bool can_avoid_first = false;
            for(int i = 1; i < (int)digits.size(); i++){
                if(digits[i] >= need_to_remove){ can_avoid_first = true; break; }
            }
            if(!can_avoid_first){
                // Must change first digit, but can't set to 0
                // So we need 2 moves
                ans = 2;
            }
        }
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