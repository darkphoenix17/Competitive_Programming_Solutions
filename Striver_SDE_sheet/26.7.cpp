class Solution {
public:
	//Recursion + Memoization
	int dp[1001][1001];
	bool check(string s, int i, int j) {
		while (i < j) {
			if (s[i] != s[j]) return false;
			i++;
			j--;
		}
		return true;
	}
	int solve(string s, int i, int j) {
		if (i >= j) return 0;
		if (check(s, i, j)) return 0;

		if (dp[i][j] != -1) return dp[i][j];

		int left, right;
		int ans = INT_MAX;
		for (int k = i; k < j; k++) {
			if (dp[i][k] != -1) left = dp[i][k];
			else {
				left = solve(s, i, k);
				dp[i][k] = left;
			}
			if (dp[k + 1][j] != -1) right = dp[k + 1][j];
			else {
				right = solve(s, k + 1, j);
				dp[k + 1][j] = right;
			}
			int tmp_ans = left + 1 + right;
			if (ans > tmp_ans) ans = tmp_ans;
			//dp[i][j]=min(dp[i][j],tmp_ans);
		}
		return dp[i][j] = ans;
	}
	int palindromicPartition(string str) {
		memset(dp, -1, sizeof(dp));
		return solve(str, 0, str.length() - 1);
	}

	//DP Top Down Approach
	int palindromicPartition(string str) {
		int n = str.length();

		/* Create two arrays to build the solution in bottom up manner
		C[i][j] = Minimum number of cuts needed for palindrome partitioning of substring str[i..j]
		P[i][j] = true if substring str[i..j] is palindrome, else false
		Note that C[i][j] is 0 if P[i][j] is true */
		int cut[n][n];
		bool p[n][n];

		// Every substring of length 1 is a palindrome
		for (int i = 0; i < n; i++) {
			p[i][i] = true;
			cut[i][i] = 0;
		}
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i < n - l + 1; i++) { //i be the starting index of len 2
				int j = l + i - 1; //Ending index

				// If L is 2, then we just need to compare two characters. Else need to check two corner characters and value of P[i+1][j-1]
				if (l == 2) p[i][j] = (str[i] == str[j]);
				else p[i][j] = (str[i] == str[j]) && p[i + 1][j - 1];

				// IF str[i..j] is palindrome, then C[i][j] is 0
				if (p[i][j] == true) {
					cut[i][j] = 0;
				}
				else {
					//// Make a cut at every possible location starting from i to j, and get the minimum cost cut.
					cut[i][j] = INT_MAX;
					for (int k = i; k < j; k++) {
						cut[i][j] = min(cut[i][k] + cut[k + 1][j] + 1, cut[i][j]);
					}
				}
			}
		}
		return cut[0][n - 1];
	}
};