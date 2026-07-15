#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<ll> arr(n);              // f(x)
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<ll> diff(n - 1);         // first difference
    for(int i = 1; i < n; i++){
        diff[i - 1] = arr[i] - arr[i - 1];
    }

    vector<ll> ans(n, 0);

    // Step 1: compute a2 ... a(n-1) using second difference
    for(int i = 1; i < n - 1; i++){
        ans[i] = (diff[i] - diff[i - 1]) / 2;
    }

    // Step 2: compute total sum S = a1 + ... + an
    // Using:
    // diff[0] = f(2) - f(1)
    // = a1 - (a2 + a3 + ... + an)
    // = a1 - (S - a1)
    // = 2a1 - S

    ll middle_sum = 0;
    for(int i = 1; i < n - 1; i++){
        middle_sum += ans[i];
    }

    // Let S = a1 + middle_sum + an
    // diff[0] = 2a1 - S
    // diff[n-2] = S - 2an

    // From diff[0] + diff[n-2]:
    // diff[0] + diff[n-2] = 2a1 - S + S - 2an
    // = 2(a1 - an)

    ll equation1 = diff[0];
    ll equation2 = diff[n - 2];

    // Solve system:
    // 2a1 - S = equation1
    // S - 2an = equation2
    // S = a1 + middle_sum + an

    // From first:
    // S = 2a1 - equation1

    // Plug into S expression:
    // 2a1 - equation1 = a1 + middle_sum + an
    // a1 - equation1 = middle_sum + an
    // a1 - an = middle_sum + equation1

    ll delta = middle_sum + equation1;  // a1 - an

    // Also from diff[n-2]:
    // equation2 = S - 2an
    // S = equation2 + 2an

    // Equate S:
    // 2a1 - equation1 = equation2 + 2an
    // 2a1 - 2an = equation1 + equation2
    // 2(a1 - an) = equation1 + equation2

    // So:
    // a1 - an = (equation1 + equation2)/2

    ll delta2 = (equation1 + equation2) / 2;

    // They must match
    // Use delta2 (mathematically correct one)

    ll diff_a = delta2;

    // Now:
    // a1 = an + diff_a
    // S = a1 + middle_sum + an
    // But S = 2a1 - equation1

    // Replace:
    // 2a1 - equation1 = a1 + middle_sum + an
    // a1 - equation1 = middle_sum + an

    // an = a1 - diff_a
    // Plug:
    // a1 - equation1 = middle_sum + a1 - diff_a
    // -equation1 = middle_sum - diff_a
    // diff_a = middle_sum + equation1   (consistency check)

    // Now solve directly:

    // Using:
    // S = middle_sum + a1 + an
    // and
    // S = 2a1 - equation1

    // Substitute an = a1 - diff_a

    // 2a1 - equation1
    // = middle_sum + a1 + (a1 - diff_a)
    // = middle_sum + 2a1 - diff_a

    // Cancel 2a1:
    // -equation1 = middle_sum - diff_a
    // diff_a = middle_sum + equation1

    // So consistent.
    // Now compute a1 from:
    // a1 - an = diff_a
    // and
    // diff[n-2] = S - 2an

    // Use simpler formula:

    // S = middle_sum + a1 + an
    // equation2 = S - 2an
    // equation2 = middle_sum + a1 + an - 2an
    // equation2 = middle_sum + a1 - an
    // equation2 = middle_sum + diff_a

    // So consistency:
    // diff_a = equation2 - middle_sum

    // Finally compute a1:

    ll an = (equation2 - middle_sum - diff_a) / 2;
    ll a1 = an + diff_a;

    ans[0] = a1;
    ans[n - 1] = an;

    for(int i = 0; i < n; i++){
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