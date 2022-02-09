class Solution {
public:
	//Recursion + Memoization
	int dp[102][102];
	int solve(int x, int y, int cutl, int cutr, vector<int>& cut) {
		if (cutl > cutr) return 0;
		int ans = 1e7;
		if (dp[cutl][cutr] != -1) return dp[cutl][cutr];
		for (int k = cutl; k <= cutr; k++) {
			int cost = solve(x, cut[k], cutl, k - 1, cut) + solve(cut[k], y, k + 1, cutr, cut);
			ans = min(cost + y - x, ans);
		}
		return dp[cutl][cutr] = ans;
	}
	int minCost(int n, vector<int>& cuts) {
		memset(dp, -1, sizeof(dp));
		sort(cuts.begin(), cuts.end());
		return solve(0, n, 0, cuts.size() - 1, cuts);
	}


	//DP Top Down Approach
	int minCost(int n, vector<int>& cuts) {
		int min_ind = INT_MAX;
		int max_ind = INT_MIN;
		vector<int> cut_ind;
		for (auto x : cuts) {
			min_ind = min(min_ind, x);
			max_ind = max(max_ind, x);
			cut_ind.push_back(x);
		}
		if (min_ind != 0) cut_ind.push_back(0);
		if (max_ind != n) cut_ind.push_back(n);

		sort(cut_ind.begin(), cut_ind.end());
		int N = cut_ind.size();

		int dp[103][103];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = 0;
			}
		}
		for (int gap = 2; gap < N; gap++) {
			for (int i = 0, j = gap; i < N && j < N; i++, j++) {
				int ans = INT_MAX;
				for (int k = i + 1; k < j; k++) {
					ans = min(ans, dp[i][k] + dp[k][j]);
				}
				dp[i][j] = ans + cut_ind[j] - cut_ind[i];
			}
		}
		return dp[0][N - 1];
	}
};