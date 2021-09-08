//two pointer approach
class Solution {
public:
	int expandOnCenter(string s, int left, int right) {
		int l = left, r = right;
		while (l >= 0 && r < s.length() && s[l] == s[r]) {
			l--;
			r++;
		}
		return r - l - 1;
	}
	string longestPalindrome(string s) {
		if (s.length() < 1) return "";
		int ff = 0, ll = 0;
		for (int i = 0; i < s.length(); i++) {
			int l1 = expandOnCenter(s, i, i); //for odd length palindrome
			int l2 = expandOnCenter(s, i, i + 1); //for even length palindrome
			int len = max(l1, l2);
			if (len > ll - ff) {
				ff = i - (len - 1) / 2;
				ll = i + len / 2;
			}
		}
		return s.substr(ff, ll - ff + 1);
	}
};