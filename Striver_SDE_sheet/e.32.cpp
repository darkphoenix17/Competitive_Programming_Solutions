class Solution {
public:
	vector<long long> dp;
	long long solve(vector<vector<int>> &q, int cur) {
		if (cur >= q.size()) return 0;
		if (cur == q.size() - 1) return 1ll * q[cur][0];

		if (dp[cur] != -1) return dp[cur];
		long long point = solve(q, cur + q[cur][1] + 1) + 1ll * q[cur][0];

		return dp[cur] = max(point, solve(q, cur + 1));
	}
	long long mostPoints(vector<vector<int>>& questions) {
		int n = questions.size();
		dp.resize(n + 1, -1);
		return solve(questions, 0);
	}
};