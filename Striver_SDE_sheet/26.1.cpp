class Solution {
public:
	//Recursion + Memoization
	int dp[202][202];
	int mini(int a, int b, int c) {
		return min(a, min(b, c));
	}
	int solve(int x, int y, vector<vector<int>>& m) {
		if (x < 0 || y < 0) return INT_MAX;
		if (x == 0 && y == 0) return m[x][y];
		if (dp[x][y] != -1) return dp[x][y];
		int way1 = solve(x - 1, y, m);
		int way2 = solve(x, y - 1, m);
		dp[x][y] = m[x][y] + min(way1, way2);
		return dp[x][y];
	}
	int minPathSum(vector<vector<int>>& grid) {
		memset(dp, -1, sizeof(dp));
		return solve(grid.size() - 1, grid[0].size() - 1, grid);
	}

	//DP Top Down Approach
	int minPathSum(vector<vector<int>>& m) {
		int dp[202][202];
		dp[0][0] = m[0][0];

		for (int i = 1; i < m.size(); i++)  dp[i][0] = dp[i - 1][0] + m[i][0];
		for (int j = 1; j < m[0].size(); j++)   dp[0][j] = dp[0][j - 1] + m[0][j];

		for (int i = 1; i < m.size(); i++) {
			for (int j = 1; j < m[0].size(); j++) {
				dp[i][j] = m[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m.size() - 1][m[0].size() - 1];
	}
};