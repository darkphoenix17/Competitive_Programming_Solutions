class Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		int m = points[0].size();
		long long dp[n + 1][m + 1];
		for (int i = 1; i <= m; i++) {
			dp[1][i] = points[0][i - 1];
		}
		long long ans = 0;
		for (int i = 2; i <= n; i++) {
			long long pre[m + 1];
			long long suf[m + 1];
			for (int j = 1; j <= m; j++) {
				if (j == 1) {
					pre[j] = dp[i - 1][j];
					continue;
				}
				pre[j] = max(pre[j - 1] - 1, dp[i - 1][j]);
			}
			for (int j = m; j >= 1; j--) {
				if (j == m) {
					suf[j] = dp[i - 1][j];
					continue;
				}
				suf[j] = max(suf[j + 1] - 1, dp[i - 1][j]);
			}
			for (int j = 1; j <= m; j++) {
				dp[i][j] = max(pre[j], suf[j]) + points[i - 1][j - 1];
			}
		}
		for (int j = 1; j <= m; j++)  ans = max(ans, dp[n][j]);
		return ans;
	}
};