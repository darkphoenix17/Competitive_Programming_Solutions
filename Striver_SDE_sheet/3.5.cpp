class Solution {
public:
	int countpath(int i, int j, int n, int m, vector<vector<int>> &dp) {
		if (i == n - 1 && j == m - 1) return 1;
		if (i >= n || j >= m) return 0;
		if (dp[i][j] != -1) return dp[i][j];
		dp[i][j] = countpath(i + 1, j, n, m, dp) + countpath(i, j + 1, n, m, dp);
		return dp[i][j];
	}
	int uniquePaths(int n, int m) { //n=rows, m=cols
		vector<vector<int>> dp(n, vector<int>(m, -1));
		return countpath(0, 0, n, m, dp);
	}
};