class Solution {
public:
	int findFinalValue(vector<int>& nums, int original) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int ind = lower_bound(nums.begin(), nums.end(), original) - nums.begin();
		int cur = original;
		for (int i = ind; i < n; i++) {
			if (nums[i] == cur) {
				cur *= 2;
			}
			if (nums[i] > cur) break;
		}
		return cur;

	}
};