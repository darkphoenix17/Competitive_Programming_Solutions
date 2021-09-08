class Solution {
public:
	int myAtoi(string s) {
		string ans;
		long m_ans;
		bool f;
		int i = 0;

		//ignore white spaces
		while (s[i] == ' ') {
			++i;
		}

		//checking pos or neg
		if (s[i] == '-' || s[i] == '+') {
			ans += s[i];
			++i;
		}

		//ignoring zero
		while (s[i] == '0') {
			++i;
		}

		//string interger
		for (; i < s.size(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				ans += s[i];
			} else {
				break;
			}
		}
		//cout << "ans " << ans;
		if (!ans.empty()) {
			stringstream temp;
			temp << ans;
			temp >> m_ans;
		} else
			m_ans = 0;

		//boundary cases
		if (m_ans < INT_MIN) {
			return INT_MIN;
		} else if (m_ans > INT_MAX) {
			return INT_MAX;
		} else if (m_ans >= INT_MIN && m_ans <= INT_MAX) {
			return m_ans;
		} else
			return 0;

	}
};