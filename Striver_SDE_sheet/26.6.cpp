class Solution
{
public:
	//Recrusion + Memoization
	unordered_map<int, bool> dp;	//to store the bool that till an index i the prefix string to that index is found in the dictionary or not.
	bool check(string s, vector<string> &b) {
		for (int i = 0; i < b.size(); i++) {
			if (b[i].compare(s) == 0) return true;
		}
		return false;
	}
	//HEre we are shortening down the segment of string a and finding the letter in the dictionary through check funct.
	//For Memoization we have used unordered_map which does check in O(1)
	bool solve(string s, vector<string>& b) {
		int n = s.size();
		if (n == 0) return true;
		if (dp.find(n) != dp.end()) return dp[n];
		bool ans = false;
		for (int i = 1; i <= n; i++) {
			if (check(s.substr(0, i), b) && solve(s.substr(i, n - i), b)) return dp[n] = true; //if till current i the prefix string is matching then repeat the same for the suffix part the string a. if by end of the string all the letter the last letter's prefix value is true means all the substring can be found in the dictionary.
		}
		return dp[n] = false;
	}
	int wordBreak(string a, vector<string> &b) {
		//memset(dp,-1,sizeof(dp));
		return solve(a, b);
	}


	//DP top down Approach
	bool check(string s, vector<string> &b) {
		for (int i = 0; i < b.size(); i++) {
			if (b[i].compare(s) == 0) return true;
		}
		return false;
	}
	int wordBreak(string a, vector<string> &b) {
		int n = a.size();
		vector<bool> dp(n + 1, false);
		//dp[0]=true;
		for (int i = 1; i <= n; i++) {
			if (dp[i] == false && check(a.substr(0, i), b)) dp[i] = true;  //check if the current prefix string till i is found in dictionary or not
			if (dp[i] == true) { //If found then look ahead of the string for the next substring after i till some j and check it's presence in the dictionary.
				if (i == n) return true;
				for (int j = i + 1; j <= n; j++) {
					if (dp[j] == false && check(a.substr(i, j - i), b)) dp[j] = true;
					if (j == n && dp[j] == true) return true;
				}
			}
		}
		return false;
	}
};
