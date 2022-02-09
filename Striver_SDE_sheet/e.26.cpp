class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> od, ev, ans;
		for (int i = 0; i < nums.size(); i++) {
			if (i % 2 == 1) od.push_back(nums[i]);
			else ev.push_back(nums[i]);
		}
		sort(od.rbegin(), od.rend());
		sort(ev.begin(), ev.end());
		for (int i = 0; i < min(od.size(), ev.size()); i++) {
			ans.push_back(ev[i]);
			ans.push_back(od[i]);
		}
		if (nums.size() % 2 == 1) {
			ans.push_back(ev[ev.size() - 1]);
		}
		return ans;
	}
};