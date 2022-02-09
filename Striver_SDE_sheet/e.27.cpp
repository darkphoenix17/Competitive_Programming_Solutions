class Solution {
public:
	long long smallestNumber(long long num) {
		string s;
		if (num == 0) return num;
		bool neg = false;
		if (num < 0) {
			neg = true;
			num *= -1;
		}
		s = to_string(num);
		sort(s.begin(), s.end());
		if (!neg) {
			int i = -1;
			while (1 && i + 1 < s.length()) {
				if (s[i + 1] != '0') {
					i++;
					break;
				}
				i++;
			}
			swap(s[0], s[i]);
			return stol(s, nullptr, 10);
		}
		else {
			string res = string(s.rbegin(), s.rend());
			return -1 * stol(res, nullptr, 10);
		}
	}
};