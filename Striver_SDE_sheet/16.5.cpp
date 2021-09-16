class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string s = countAndSay(n - 1);
		//string s="112333432212";
		string res = "";
		for (int i = 0; i < s.size(); i++) {
			int cnt = 1;
			while (i + 1 < s.size() && s[i] == s[i + 1]) i++, cnt++;
			res += cnt + '0';
			res += s[i];
		}
		return res;
	}
};