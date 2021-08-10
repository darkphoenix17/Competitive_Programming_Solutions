//o(n^3)time o(1) space Approach
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		/*
		Logic:
		Here we take advantage of the sort, Inside loop i and j, we are sure to get the other two numbers at the right half of the array.
		Approach:
		So we use 2 pointer approach in that half where left pointer points j+1 and right pointer points last element of the array.
		Also here if value_of_left<value_of_right and left on increasing increases the value and right on decreasing reduce the value so we can cover that half section of the array in O(n) this way:
		if the value of sum of num_3 and num_4 is less then the required, we move left pointer further to increase the value of the sum and same way if the value of sum of num 3 and 4 is more then the required, we will reduce the right pointer to decrease the sum value to match our required sum.
		Another point to notice is to avoid duplicate answer we have shift through the duplicate values of the pointers ONLY after we have found a combination. because if we skip duplicate on every step then there is a chance that you come up with sum by two same number as answer but you jumped through duplicate so that the left<right condition is skipped which could have given an answer. Basically we will skip answers having same value inside the right half or the array where the 2 pointer is used.
		*/
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				int left = j + 1, right = n - 1;
				int item = target * 1ll - nums[i] - nums[j];
				while (left < right) {
					int temp_sum = nums[left] + nums[right];
					if (temp_sum < item) left++;
					else if (temp_sum > item) right--;
					else {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[left]);
						temp.push_back(nums[right]);
						ans.push_back(temp);
						while (left < right && nums[left] == temp[2]) left++;
						while (left < right && nums[right] == temp[3]) right--;
					}

				}
				while (j < n - 1 && nums[j + 1] == nums[j]) j++;
			}
			while (i < n - 1 && nums[i + 1] == nums[i]) i++;
		}
		return ans;
	}
};

//o(n^3logn)time and o(n) space approach
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		//https://www.geeksforgeeks.org/binary-search-functions-in-c-stl-binary_search-lower_bound-and-upper_bound/
		int n = nums.size();
		set<vector<int>> s;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				for (int k = j + 1; k < n - 1; k++) {
					long long item = target * 1ll - nums[i] * 1ll - nums[j] * 1ll - nums[k] * 1ll; //to avoid int overflow we work with long long
					if (item > INT_MAX) continue;
					if (binary_search(nums.begin() + k + 1, nums.end(), (int)item)) {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						temp.push_back(target - nums[i] - nums[j] - nums[k]);
						s.insert(temp);
					}
				}
			}
		}
		vector<vector<int>> ans;
		for (auto x : s) {
			ans.push_back(x);
		}
		return ans;
	}
};