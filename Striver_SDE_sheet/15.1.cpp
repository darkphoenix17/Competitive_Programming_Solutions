class Solution {
public:
	string reverseWords(string s) {
		int len = s.length();
		int ff = -1, ll, i;
		vector<string> v;
		for (i = 0; i < len; i++) {
			if (s[i] == ' ') {
				continue;
			}
			int start = i;
			int offset = 0;
			while (s[i] != ' ' && i + 1 < len) {
				offset++;
				i++;
			}
			if (s[i] != ' ' && i == len - 1) {
				offset++;
			}
			v.push_back(s.substr(start, offset));
		}
		//reverse(v.begin(),v.end());
		string ans = "";
		for (i = v.size() - 1; i >= 0; i--) {
			ans += v[i];
			if (i != 0) ans += " ";
		}
		return ans;
	}
};