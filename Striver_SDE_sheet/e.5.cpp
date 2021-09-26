class Solution {
public:
	int dp[100005];
	int solve(vector<pair<int, pair<int, int>>> &v, int ind, int N) {
		if (ind >= N) return 0;
		if (dp[ind] != -1) return dp[ind];
		int newstart = v[ind].second.first;
		pair<int, pair<int, int>> p = {newstart, {0, 0}};
		int newInd = upper_bound(v.begin(), v.end(), p) - v.begin();
		//int newInd=newInditr-v.begin();
		return dp[ind] = max(solve(v, newInd, N) + v[ind].second.second, solve(v, ind + 1, N));
	}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		vector<pair<int, pair<int, int>>> v;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < startTime.size(); i++) {
			v.push_back({startTime[i], {endTime[i], profit[i]}});
		}
		sort(v.begin(), v.end());
		int ans = solve(v, 0, v.size());
		return ans;
	}
};