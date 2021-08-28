class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int lo = 0, hi = n - 1;
		int f = 0, ans;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) {
				f = 1;
				ans = mid;
				break;
			}
			if (target > nums[mid]) {
				if (target >= nums[0] && nums[mid] >= nums[0] || target < nums[0] && nums[mid] < nums[0]) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
			else {
				if (target >= nums[0] && nums[mid] >= nums[0] || target < nums[0] && nums[mid] < nums[0]) {
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
		}
		if (!f) return -1;
		else return ans;
	}
};