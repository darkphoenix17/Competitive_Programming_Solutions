class Solution {
public:
	void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
		if (ind == arr.size()) {
			if (target == 0) {
				ans.push_back(ds);
			}
			return;
		}
		if (arr[ind] <= target) {
			ds.push_back(arr[ind]);
			findCombination(ind, target - arr[ind], arr, ans, ds);
			ds.pop_back();
		}
		findCombination(ind + 1, target, arr, ans, ds);
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> ds;
		findCombination(0, target, candidates, ans, ds);
		return ans;
	}
};

class Solution {
public:
	void combinationSum(vector<int>& candidates, int target, int start, vector<int> &temp, vector<vector<int>> &ans, int i) {

		if ( i == candidates.size()) {
			if (start == target) ans.push_back(temp);
			return;
		}
		if (start > target) {
			return;
		}
		temp.push_back(candidates[i]);
		combinationSum(candidates, target, start + candidates[i], temp, ans, i);
		temp.pop_back();
		combinationSum(candidates, target, start, temp, ans, i + 1);


	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> temp;
		vector<vector<int>> ans;
		combinationSum(candidates, target, 0, temp, ans, 0);
		return ans;
	}
};