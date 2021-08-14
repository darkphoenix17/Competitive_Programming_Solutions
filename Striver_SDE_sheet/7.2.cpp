class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		if (n == 0 || n == 1 || n == 2) return ans;
		for (int i = 0; i < n; i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
				int a = nums[i];
				int l = i + 1;
				int r = n - 1;
				while (l < r) {
					if (nums[l] + nums[r] == -a) {
						int b = nums[l], c = nums[r];
						vector<int> tmp;
						tmp.push_back(a);
						tmp.push_back(b);
						tmp.push_back(c);
						ans.push_back(tmp);
						while (l + 1 < n && nums[l] == b) {
							l++;
						}
						while (r - 1 > i && nums[r] == c) {
							r--;
						}
						continue;
					}
					if (nums[l] + nums[r] + a < 0) {
						l++;
					}
					else if (nums[l] + nums[r] + a > 0) {
						r--;
					}
				}
			}
		}
		return ans;
	}
};