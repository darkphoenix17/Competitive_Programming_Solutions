class Solution
{
public:
	// Recursion + Memoization
	int dp[202][202];
	int solve(int e, int k) {
		if (dp[e][k] != -1) return dp[e][k];

		if (e == 1) return k;
		if (k == 1 || k == 0) return k;


		int ans = INT_MAX;
		for (int i = 1; i <= k; i++) {
			int tmp_ans = max(solve(e - 1, i - 1), solve(e, k - i));
			ans = min(tmp_ans, ans);
		}
		return dp[e][k] = ans + 1;
	}
	//Function to find minimum number of attempts needed in
	//order to find the critical floor.
	int eggDrop(int n, int k) {
		memset(dp, -1, sizeof(dp));
		return solve(n, k);
	}


	//DP Top Down Approach
	int eggDrop(int n, int k) {
		long long dp[n + 1][k + 1];
		for (int i = 1; i <= k; i++) dp[1][i] = i;
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= k; j++) {
				long long ans = INT_MAX;
				for (int x = 0; x <= j; x++) {
					long long res = max(dp[i - 1][x - 1], dp[i][j - x]);
					ans = min(res, ans);
				}
				dp[i][j] = ans + 1;
			}
		}
		return dp[n][k];

	}
};