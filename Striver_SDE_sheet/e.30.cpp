class Solution {
public:
	vector<string> divideString(string giv, int k, char fill) {
		string s = giv;
		int l = s.length();
		vector<string> ans;
		int rem = (k - (l % k)) % k;
		for (int i = 0; i < rem; i++) s += fill;
		l += rem;
		for (int i = 0; i < l; i += k) {
			ans.push_back(s.substr(i, k));
		}
		return ans;
	}
};