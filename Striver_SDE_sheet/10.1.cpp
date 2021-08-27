// through checker bool
class Solution {
public:
	void funct(vector<vector<int>> &ans, vector<bool> &check , vector<int> & nums, vector<int> &tmp) {
		if (tmp.size() == nums.size()) {
			ans.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!check[i]) {
				tmp.push_back(nums[i]);
				check[i] = true;
				funct(ans, check, nums, tmp);
				check[i] = false;
				tmp.pop_back();
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> check(nums.size(), false);
		vector<int> tmp;
		vector<vector<int>> ans;
		funct(ans, check, nums, tmp);
		return ans;
	}
};

// through index increment
class Solution {
private:
	void funct(int index, vector<int> &nums, vector<vector<int>> &ans) {
		if (index == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); i++) {
			swap(nums[index], nums[i]);
			funct(index + 1, nums, ans);
			swap(nums[index], nums[i]);
		}

	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		funct(0, nums, ans);
		return ans;
	}
};