// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << maxLen(A, N) << endl;
	}
}
// } Driver Code Ends

int maxLen(int arr[], int n) {
	int res = 0;
	unordered_map<int, int> mp;
	int pre_sum = 0;
	for (int i = 0; i < n; i++) {
		pre_sum += arr[i];
		if (pre_sum == 0) {
			res = i + 1;
		}
		if (mp.find(pre_sum) != mp.end()) {
			res = max(res, i - mp[pre_sum]);
		}
		if (mp.find(pre_sum) == mp.end()) {
			mp[pre_sum] = i;
		}
	}
	return res;
}
