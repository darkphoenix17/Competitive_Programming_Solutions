class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		int lo = 0, hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			int a;
			if (nums[mid] == nums[mid + 1]) {
				a = mid;
			}
			else if (nums[mid] == nums[mid - 1]) {
				a = mid - 1;
			}
			else if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
				lo = mid;
				hi = mid;
				continue;
			}
			if (a % 2 == 0) {
				lo = a + 2;
			}
			else {
				hi = a - 1;
			}
		}
		return nums[lo];
	}
};

class Solution {
public:
	int singleNonDuplicate(vector<int>& a) {
		int n = a.size();
		int c = a[0];
		for (int i = 1; i < n; i++)
		{
			c ^= a[i];
		}
		return c;
	}
};

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int low = 0, high = nums.size() - 2;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (nums[mid] == nums[mid ^ 1]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return nums[low];
	}
};