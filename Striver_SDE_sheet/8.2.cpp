// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

//ERROR CODE
//  // } Driver Code Ends
// class Solution{
//     public:
//     //Function to find the minimum number of platforms required at the
//     //railway station such that no train waits.
//     int findPlatform(int arr[], int dep[], int n)
//     {
//         vector<int> v;
//         v.push_back(1);
//         int ans=0;
//         sort(arr,arr+n);
//         sort(dep, dep+n);
//         //vector<vector<int>> v(2405);
//     	for(int i=0;i<n;i++){
//     	    int lo=lower_bound(arr, arr+n, arr[i])-arr;
//     	    int hi=upper_bound(arr, arr+n, dep[i])-arr;
//     	   // cout<<arr[i]<<" "<<dep[i]<<endl;
//     	   // cout<<lo<<" "<<hi<<endl;
//     	    ans=max(hi-lo,ans);
//     	}
//     	return ans;
//     }
// };

class Solution {
public:
	//Function to find the minimum number of platforms required at the
	//railway station such that no train waits.
	int findPlatform(int arr[], int dep[], int n)
	{
		sort(arr, arr + n);
		sort(dep, dep + n);
		int plat = 1;
		int ans = 1;
		int i = 1, j = 0;
		while (i < n & j < n) {
			if (arr[i] <= dep[j]) {
				plat++;
				i++;
			}
			else {
				plat--;
				j++;
			}
			if (plat > ans) {
				ans = plat;
			}
		}
		return ans;
	}
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		int dep[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int j = 0; j < n; j++) {
			cin >> dep[j];
		}
		Solution ob;
		cout << ob.findPlatform(arr, dep, n) << endl;
	}
	return 0;
}  // } Driver Code Ends