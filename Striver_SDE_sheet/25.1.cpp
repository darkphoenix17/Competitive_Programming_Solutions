class Solution {
public:
	//Kadane Algorithm
	//Note: The pick point for this problem is that we can get the maximum product from the product of two negative numbers too
	int maxProduct(vector<int>& nums) {
		int prod1 = nums[0], prod2 = nums[0], ans = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			int temp = max(nums[i], max(prod1 * nums[i], prod2 * nums[i]));
			prod2 = min(nums[i], min(prod1 * nums[i], prod2 * nums[i]));
			prod1 = temp;

			ans = max(ans, prod1);
		}
		return ans;

	}
	//Two Pointer Approach
	int maxProduct(vector<int>& nums) {
		int maxLeft = INT_MIN;
		int maxRight = INT_MIN;

		int prod = 1;

		bool zeroPresent =  false;

		for (auto i : nums) {
			prod *= i;
			if (i == 0) {
				zeroPresent = true;
				prod = 1;
				continue;
			}
			maxLeft = max(maxLeft, prod);
		}

		prod = 1;
		for (int j = nums.size() - 1; j >= 0; j--) {
			prod *= nums[j];
			if (nums[j] == 0) {
				zeroPresent = true;
				prod = 1;
				continue;
			}
			maxRight = max(maxRight, prod);
		}

		if (zeroPresent) return max(max(maxLeft, maxRight), 0);
		return max(maxLeft, maxRight);
	}
};