class Solution {
public:
	//TC=O(N*LogN) SC=O(1)
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		sort(nums.begin(), nums.end());
		int ans = 1;
		int prev = nums[0];
		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (nums[i] == prev + 1) {
				cur++;
			}
			else if (nums[i] != prev) {
				cur = 1;
			}
			prev = nums[i];
			ans = max(ans, cur);
		}
		return ans;
	}

	//TC=O(N) SC=O(N)
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> st;
		for (auto num : nums) {
			st.insert(num);
		}
		int ans = 0;
		for (auto num : nums) {
			if (!st.count(num - 1)) {
				int cur_num = num;
				int streak = 1;
				while (st.count(cur_num + 1)) {
					cur_num++;
					streak++;
				}
				ans = max(ans, streak);
			}
		}
		return ans;
	}
};