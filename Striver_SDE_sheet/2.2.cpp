class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		for (int i = 0; i < numRows; i++) {
			vector<int> temp;
			int val = 1;
			temp.push_back(val);
			for (int j = 0; j < i; j++) {
				val *= (i - j);
				val /= (j + 1);
				temp.push_back(val);
			}
			ans.push_back(temp);
		}
		return ans;
	}
};