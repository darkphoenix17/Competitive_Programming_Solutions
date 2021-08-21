class Solution {
public:
	void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
		if (target == 0) {
			ans.push_back(ds);
			// for(auto x:ds){
			//     cout<<x<<" ";
			// }
			// cout<<"-------"<<endl;
			return;
		}
		for (int i = ind; i < arr.size(); i++) {
			if (i > ind && arr[i] == arr[i - 1]) continue;
			//cout<<arr[i]<<" "<<ind<<" "<<target<<endl;
			if (arr[i] > target) {
				//cout<<"outofbound"<<endl;
				break;
			};
			ds.push_back(arr[i]);
			// for(auto x:ds){
			//     cout<<x<<" ";
			// }
			// cout<<"---each---"<<endl;
			findCombination(i + 1, target - arr[i], arr, ans, ds);
			ds.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> ds;
		sort(candidates.begin(), candidates.end());
		// for(auto x:candidates){
		//     cout<<x<<" ";
		// }
		// cout<<endl;
		findCombination(0, target, candidates, ans, ds);
		return ans;
	}
};