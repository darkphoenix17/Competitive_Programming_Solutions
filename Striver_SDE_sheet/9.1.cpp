// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	void findsum(vector<int> arr, int sum, int index, int N, vector<int> &v) {
		if (index == N) {
			v.push_back(sum);
			return;
		}
		findsum(arr, sum + arr[index] , index + 1, N, v);
		findsum(arr, sum, index + 1, N , v);

	}
	vector<int> subsetSums(vector<int> arr, int N) {
		vector<int> v;
		findsum(arr, 0, 0, N, v);
		sort(v.begin(), v.end());
		return v;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0 ; i < N ; i++) {
			cin >> arr[i];
		}
		Solution ob;
		vector<int> ans = ob.subsetSums(arr, N);
		for (auto sum : ans) {
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends