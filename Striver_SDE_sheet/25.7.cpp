class Solution {
public:
	// //Recursive + Memoization
	int dp[103][103];
	int solve(int arr[], int i, int j) {
		if (i == j) return 0;
		if (dp[i][j] != -1) return dp[i][j];
		dp[i][j] = INT_MAX;
		for (int k = i; k < j; k++) {
			int count = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
			dp[i][j] = min(dp[i][j], count);
		}
		return dp[i][j];
	}

	//Intution is divide and solve the sub array as we know we have the solve the matirx using parenthesis.
	int matrixMultiplication(int n, int arr[]) {
		memset(dp, -1, sizeof(dp));
		return solve(arr, 1, n - 1);
	}

	//Intution is divide and solve the sub array as we know we have the solve the matirx using parenthesis.
	//DP TopDown Approach
	int matrixMultiplication(int n, int arr[]) {
		int dp[103][103];
		for (int i = 1; i < n; i++) dp[i][i] = 0;
		//dp[i][j] states are as follow.
		//I denotes that i parenthesis are already appliecd to the chain of numbers(matrix)
		//J denotes that for I parenthesis the number of maximum possible partitions in the chain of numbers(matrix)
		for (int l = 2; l < n; l++) {
			for (int i = 1; i < n - l + 1; i++) {
				int j = i + l - 1;
				dp[i][j] = INT_MAX;
				for (int k = i; k <= j - 1; k++) {
					int count = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
					dp[i][j] = min(dp[i][j], count);
				}
			}
		}
		return dp[1][n - 1];
	}



};