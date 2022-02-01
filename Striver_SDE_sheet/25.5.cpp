class Solution {
public:
	int mini(int a, int b, int c) {
		return min(a, min(b, c));
	}

	//Recursive + Memoization
	/*
	int dp[502][502];
	int solve(string a, string b, int m, int n){
	    if(m==0) return n;  //insert all the n remaining elements of string b in a
	    if(n==0) return m;  //insert all the , remaining elements of string a in b
	    if(dp[m][n]!=-1) return dp[m][n];
	    if(a[m-1]==b[n-1])
	        return dp[m][n]=solve(a,b,m-1,n-1);
	    return dp[m][n]=1+mini(solve(a,b,m,n-1),solve(a,b,m-1,n),solve(a,b,m-1,n-1));
	}
	int minDistance(string word1, string word2) {
	    memset(dp,-1,sizeof(dp));
	    return solve(word1,word2,word1.size()-1, word2.size()-1);
	}
	*/

	//Top Down DP approach
	int minDistance(string w1, string w2) {
		int m = w1.size();
		int n = w2.size();
		int dp[m + 1][n + 1];
		for (int i = 0; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int i = 0; i <= n; i++) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (w1[i - 1] == w2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = 1 + mini(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
		return dp[m][n];
	}
};