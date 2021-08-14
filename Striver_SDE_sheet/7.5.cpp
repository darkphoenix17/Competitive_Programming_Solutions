class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0, n = nums.size();
		int i = 0;
		while (i < n) {
			if (nums[i] == 1) {
				int cnt = 1;
				while (i + 1 < n && nums[i] == nums[i + 1]) {
					i++; cnt++;
				}
				ans = max(ans, cnt);
			}
			i++;
		}
		return ans;
	}
};

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0, cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				cnt++;
			}
			else cnt = 0;
			ans = max(ans, cnt);
		}
		return ans;
	}
};