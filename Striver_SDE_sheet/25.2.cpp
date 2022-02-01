class Solution {
public:
	//longest Common Subsequence
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> lis(n);
		lis[0] = 1;

		/* Compute optimized LIS values in bottom up manner */
		for (int i = 1; i < n; i++) {
			lis[i] = 1;
			for (int j = 0; j < i; j++)
				if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1;
		}
		int ans = INT_MIN;
		for (auto x : lis) {
			ans = max(ans, x);
		}
		// Return maximum value in lis[]
		return ans;
	}
};