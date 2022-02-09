class Solution {
public:
	bool isSubsetSum(int n, vector<int>& arr, int sum) {
		bool dp[sum + 1][n + 1];
		for (int i = 0; i <= sum; i++) dp[i][0] = false;
		for (int i = 0; i <= n; i++) dp[0][i] = true;
		for (int j = 1; j <= sum; j++) {
			for (int i = 1; i <= n; i++) {
				// if(i==0) dp[i][j]=true;
				// else if(j==0) dp[i][j]=false;
				if (arr[i - 1] > j) dp[j][i] = dp[j][i - 1];
				else dp[j][i] = dp[j - arr[i - 1]][i - 1] || dp[j][i - 1];
			}
		}
		return dp[sum][n];
	}
	bool canPartition(vector<int>& nums) {
		int ans = 0;
		for (auto x : nums) {
			ans += x;
		}
		if (ans % 2) return false;
		ans /= 2;
		return isSubsetSum(nums.size(), nums, ans);
	}
};