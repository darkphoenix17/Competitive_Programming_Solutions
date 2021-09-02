class Solution {
public:
	vector<int> recoverArray(int n, vector<int>& sums) {
		sort(sums.begin(), sums.end());
		vector<int> ans;
		while (n--) {
			int diff = sums[1] - sums[0];
			unordered_map<int, int> mp;
			vector<int> ex, in;
			bool zeroOnEx = false;
			for (auto &x : sums) {
				if (!mp[x]) {
					ex.push_back(x);
					mp[x + diff]++;
					if (x == 0) zeroOnEx = true;
				}
				else {
					in.push_back(x);
					mp[x]--;
				}
			}
			if (zeroOnEx == true) {
				ans.push_back(diff);
				sums = ex;
			}
			else sums = in, ans.push_back(-1 * diff);
		}
		return ans;
	}
};