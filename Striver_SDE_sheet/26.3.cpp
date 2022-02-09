class Solution {
public:
	//Recursive + Memoization
	int dp[10005][102];
	int solve(int arr[], int sum, int cur) {
		if (sum == 0) return 1;
		if (cur < 0) return 0;
		if (dp[sum][cur] != -1) return dp[sum][cur];
		if (arr[cur] > sum) dp[sum][cur] = solve(arr, sum, cur - 1);
		// int t1=solve(arr,sum-arr[cur],cur-1);
		// int t2=solve(arr,sum,cur-1);
		else dp[sum][cur] = (solve(arr, sum - arr[cur], cur - 1) || solve(arr, sum, cur - 1));
		return dp[sum][cur];
		//return solve(arr,sum-arr[cur],cur-1) || solve()
	}
	bool isSubsetSum(int n, int arr[], int sum) {
		memset(dp, -1, sizeof(dp));
		if (solve(arr, sum, n - 1)) return true;
		else return false;
	}

	//DP Top DOwn Approach
	bool isSubsetSum(int n, int arr[], int sum) {
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

};