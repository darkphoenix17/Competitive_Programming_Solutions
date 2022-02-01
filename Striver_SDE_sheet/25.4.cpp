class Solution {
public:
	//Recursion + Memoization
	int len;
	int dp[602][101][101];
	int solve(vector<int>v[], int m_left, int n_left, int cur) {
		if ((m_left <= 0 && n_left <= 0) || cur >= len) return 0;
		if (dp[cur][m_left][n_left] != -1) return dp[cur][m_left][n_left];
		int res1 = 0, res2 = 0;
		if (v[0][cur] <= m_left && v[1][cur] <= n_left) {
			res1 = solve(v, m_left - v[0][cur], n_left - v[1][cur], cur + 1) + 1;
		}
		res2 = solve(v, m_left, n_left, cur + 1);
		return dp[cur][m_left][n_left] = max(res1, res2);
	}
	int findMaxForm(vector<string>& str, int m, int n) {
		memset(dp, -1, sizeof(dp));
		len = str.size();
		vector<int> v[2];
		for (auto x : str) {
			//cout<<x<<endl;
			int a = 0, b = 0;
			for (auto i : x) {
				if (i == '0') a++;
				else b++;
			}
			v[0].push_back(a);
			v[1].push_back(b);
		}
		// for(auto x:v[0]){
		//     cout<<x<<" ";
		// }
		// cout<<endl;
		// for(auto x:v[1]){
		//     cout<<x<<" ";
		// }
		// cout<<endl;
		return solve(v, m, n, 0);

	}
};