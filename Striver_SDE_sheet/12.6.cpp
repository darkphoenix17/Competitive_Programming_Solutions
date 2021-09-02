#include <iostream>
using namespace std;

int square(int num)
{
	int ans = 0;
	int temp = 0;
	for (int i = 30; i >= 0; i--) {
		if (temp + (1 << i) <= num) {
			ans += num << i;
			temp += 1 << i;
			//cout<<(1<<i)<<" "<<temp<<endl;
		}
	}
	return ans;
}

// Driver code
int main()
{
	// Function calls
	for (int n = 10; n <= 15; ++n)
		cout << "n = " << n << ", n^2 = " << square(n) << endl;
	return 0;
}