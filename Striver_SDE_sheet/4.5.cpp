#include <bits/stdc++.h>
using namespace std;
int subArrXor(int A[], int n, int m)
{
	int res  = 0;
	int a[n];
	a[0] = A[0];
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1] ^ A[i];
	}
	unordered_map<int, int> mp;
	int prearr = 0;
	for (int i = 0; i < n; i++) {
		int tmp = a[i] ^ m;
		res += mp[tmp];
		if (a[i] == m) {
			res++;
		}
		mp[a[i]]++;
	}
	return res;
}

int main()
{
	int arr[] = { 4, 2, 2, 6, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 6;

	cout << "Number of subarrays having given XOR is "
	     << subArrXor(arr, n, m);
	return 0;
}