class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		int n = nums.size();
		//vector<vector<int>> v(n+1);4
		vector<int> ans;
		vector<int> left(n + 1), right(n + 1);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) cnt++;
			left[i + 1] = cnt;
		}
		// for(auto x:left) cout<<x<<" ";
		// cout<<endl;
		cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] == 1) cnt++;
			right[i] = cnt;
		}
		// for(auto x:right) cout<<x<<" ";
		// cout<<endl;
		int m = 0;
		for (int i = 0; i <= n; i++) {
			m = max(left[i] + right[i], m);
			//v[left[i]+right[i]].push_back(i);
		}
		for (int i = 0; i <= n; i++) {
			if (left[i] + right[i] == m) ans.push_back(i);
		}
		return ans;
	}
};