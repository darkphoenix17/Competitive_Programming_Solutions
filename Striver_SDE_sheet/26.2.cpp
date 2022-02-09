class Solution {
public:
	//Recursion + Memoization
	int len;
	int dp[10005][15];
	int solve(vector<int>& m, int amount, int cur) {
		if (amount == 0) return 0;
		if (cur == 0) return INT_MAX - 1;
		if (dp[amount][cur] != -1) return dp[amount][cur];
		if (m[cur - 1] > amount) return dp[amount][cur] = solve(m, amount, cur - 1);
		return dp[amount][cur] = min(1 + solve(m, amount - m[cur - 1], cur), solve(m, amount, cur - 1));
	}

	int coinChange(vector<int>& coins, int amount) {
		len = coins.size();
		memset(dp, -1, sizeof(dp));
		int res = solve(coins, amount, len);
		if (res == INT_MAX - 1) return -1;
		else return res;
	}

	//DP Top Down Approach
	int coinChange(vector<int>& coins, int amount) {
		int len = coins.size();
		int dp[len + 1][amount + 1];
		for (int i = 0; i <= len; i++) dp[i][0] = 0;
		for (int i = 0; i <= amount; i++) dp[0][i] = INT_MAX - 1;

		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= amount; j++) {
				dp[i][j] = dp[i - 1][j];
				if (coins[i - 1] <= j) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
				}
			}
		}
		if (dp[len][amount] == INT_MAX - 1) return -1;
		return dp[len][amount];
	}
};