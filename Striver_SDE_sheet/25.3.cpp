class Solution {
public:
	//Recursive + Memoization
	vector<vector<int>> v; //dp matrix
	int solve(string a, string b, int m, int n) {
		if (m == 0 || n == 0) return 0;
		if (v[m][n] != -1) return v[m][n];
		if (a[m - 1] == b[n - 1]) {		//Since strings are zero based so we have to check for index - 1;
			return v[m][n] = 1 + solve(a, b, m - 1, n - 1);
		}
		else {
			return v[m][n] = max(solve(a, b, m - 1, n), solve(a, b, m, n - 1));
		}
	}
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.length();
		int n = text2.length();
		v.resize(m + 1, vector<int> (n + 1, -1));
		return solve(text1, text2, m, n);
	}


	//DP top-down approach
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.length();
		int n = text2.length();
		vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
		for (int i = 0; i <= m; i++) {
			dp[i][0] = 0;
		}
		for (int i = 0; i <= n; i++) {
			dp[0][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				//if(i==0 || j==0) dp[i][j]=0;
				if (text1[i - 1] == text2[j - 1]) { //Since strings are zero based so we have to check for index - 1;
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		return dp[m][n];
	}
};