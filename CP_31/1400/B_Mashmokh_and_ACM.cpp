#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> factors[n + 1];
	// Precompute divisors for every number 1..n
	for (int i = 1; i <= n; i++) { // O(n)
		for (int j = 1; j * j <= i; j++) { // O(sqrt(n)) per i
			if (i % j == 0) {
				factors[i].push_back(j);      // j is a divisor of i
				if (i / j != j) {
					factors[i].push_back(i / j); // add the paired divisor if distinct
				}
			}
		}
	}

	int dp[k + 1][n + 1]; // dp[len][last] = number of good sequences of length 'len' ending with value 'last'

	// Base case: sequences of length 1; any single number 1..n forms a valid sequence
	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}

	// Build DP for lengths 2..k
	for (int i = 2; i <= k; i++) {      // O(k)
		for (int j = 1; j <= n; j++) {    // O(n)
			dp[i][j] = 0;
			// Previous element must divide current 'j', so sum over all divisors of 'j'
			for (auto x : factors[j]) {    // iterate all valid predecessors of j
				dp[i][j] = (dp[i][j] + dp[i - 1][x]) % MOD; // add ways ending with x
			}
		}
	}

	int ans = 0;
	// Sum over all sequences of length k regardless of the ending value
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[k][i]) % MOD;
	}

	cout << ans << endl;
}

/*
Time Complexity (TC): O(n * sqrtn + n * k * n^1/3)
Space Complexity (SC): O(n * k)
*/
