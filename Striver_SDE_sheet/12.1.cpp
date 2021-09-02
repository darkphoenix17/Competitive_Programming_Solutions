class Solution {
public:
	// Function to check if given number n is a power of two.
	bool isPowerofTwo(long long n) {
		//cout<<n<<" "<<n-1;
		return n && (!(n & (n - 1))); //Note: As per preceding order logical not(!) has more priority then bitwise AND(&)..Hence use brackets
	}
};
