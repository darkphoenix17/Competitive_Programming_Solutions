class Solution {
public:
	// n: input to count the number of set bits
	//Function to return sum of count of set bits in the integers from 1 to n.
	int countSetBits(int n)
	{
		if (n == 0) return 0;
		int x = log(n) / log(2);
		int ans = 0;
		int max2 = 1;
		max2 = max2 << x;
		ans += n + 1 - max2;
		ans += (max2 >> 1) * x;
		ans += countSetBits(n - max2);
		return ans;
	}
};
