class Solution {
public:
	double Pow(double x, long long n) {
		if (n == 0) return 1.00;
		double ans = 1.0;
		while (n) {
			if (n % 2) {
				ans *= x;
				n -= 1;
			}
			else {
				x = x * x;
				n /= 2;
			}
		}
		return ans;
	}
	// look at the edge case of x^n;
	// Minimum is 2^-31 which when multiplied by -1 will get overflowed as intergers max value is 2^31-1; Hence take long long;
	double myPow(double x, int n) {
		long long nn = (1ll * n);
		if (n < 0) {
			nn *= -1;
			return double(1) / Pow(x, nn);
		}
		else return Pow(x, n);
	}
};