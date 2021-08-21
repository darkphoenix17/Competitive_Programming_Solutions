//Time Optimized
class Solution {
private:
	void findSubsets(int ind, vector<int> & nums, vector<int> &ds, vector<vector<int>> &ans) {
		ans.push_back(ds);
		for (int i = ind; i < nums.size(); i++) {
			if (i != ind && nums[i] == nums[i - 1]) continue;
			ds.push_back(nums[i]);
			findSubsets(i + 1, nums, ds, ans);
			ds.pop_back();
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> ans;
		vector<int> ds;
		sort(nums.begin(), nums.end());
		findSubsets(0, nums, ds, ans);
		return ans;
	}
};

//Memory Optimized
class Solution {
private:
	map<vector<int>, bool> m;
	vector<vector<int>> ans;
	void search(int k, int &n, vector<int> &nums, vector<int> &subset) {
		if (k == n) {
			vector<int> temp = subset;
			sort(temp.begin(), temp.end());
			if (m.find(temp) == m.end()) {
				m[temp] = true;
				ans.push_back(temp);
			}
		}
		else {
			subset.push_back(nums[k]);
			search(k + 1, n, nums, subset);
			subset.pop_back();
			search(k + 1, n, nums, subset);
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		int n = nums.size();
		vector<int> subset;
		search(0, n, nums, subset);
		return ans;
	}
};