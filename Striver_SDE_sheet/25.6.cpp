class Solution {


public:
	//Recursive + Memoization
	int dp[1003][1003];
	int solve(vector<int>& arr, int cur, int prev, int size) {
		if (cur == size) return 0;
		if (dp[prev][cur] != -1) return dp[prev][cur];
		int x = 0, y = 0;
		if (arr[prev] < arr[cur]) x = arr[cur] + solve(arr, cur + 1, cur, size);
		y = solve(arr, cur + 1, prev, size);
		return dp[prev][cur] = max(x, y);
	}
	int maxSumIS(int arr[], int n)  {
		memset(dp, -1, sizeof(dp));
		vector<int> v;
		v.push_back(INT_MIN);
		for (int i = 0; i < n; i++) {
			v.push_back(arr[i]);
		}
		return solve(v, 1, 0, n + 1);
	}

	//DP
	int maxSumIS(int arr[], int n)  {
		int dp[n + 1] = {0};
		dp[0] = arr[0];
		for (int i = 1; i < n; i++) {
			dp[i] = arr[i];
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i]) {
					dp[i] = max(arr[i] + dp[j], dp[i]);
				}
			}
		}
		int ans = 0;
		for (auto x : dp) ans = max(ans, x);
		return ans;
	}
};