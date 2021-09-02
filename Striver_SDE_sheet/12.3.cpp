class Solution {
public:
	int divide(int dividend, int divisor) {
		long long dvnd = dividend;
		long long divi = divisor;
		int sign;
		if ((dvnd > 0 && divi > 0) || (dvnd < 0 && divi < 0)) {
			sign = 1;
		}
		else {
			sign = -1;
		}
		if (dvnd == 0) return 0;
		if (dvnd == (long long)INT_MIN && divi == -1) {
			return INT_MAX;
		}
		dvnd = abs(dvnd);
		divi = abs(divi);
		long long temp = 0, ans = 0;
		for (int i = 31; i >= 0; i--) {
			if (temp + (divi << i) <= dvnd) {
				temp += (divi << i);
				ans += 1 << i;
			}
		}
		if (sign == 1) {
			return ans;
		}
		else return -ans;

	}
};