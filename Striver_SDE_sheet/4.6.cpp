class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> mp;
		int n = s.length();
		int l = 0, r = 0, ans = 0;
		while (r < n && l <= r) {
			if (mp.find(s[r]) == mp.end()) {
				mp.insert(s[r]);
				ans = max(ans, r - l + 1);
				r++;
			}
			else if (mp.find(s[r]) != mp.end()) {
				mp.erase(s[l]);
				l++;
			}
		}
		return ans;
	}
};


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> mp;
		int n = s.length();
		int l = 0, r = 0, ans = 0;
		while (r < n) {
			if (mp.find(s[r]) != mp.end()) {
				l = max(l, mp[s[r]] + 1);
			}
			mp[s[r]] = r;
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};