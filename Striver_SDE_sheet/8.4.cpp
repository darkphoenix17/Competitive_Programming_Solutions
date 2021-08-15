// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value;
	int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
	static bool compare(pair<double, Item*> &a, pair<double, Item*> &b) {
		return a.first > b.first;
	}
	//Function to get the maximum total value in the knapsack.
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		vector<pair<double, Item*>> v(n);
		for (int i = 0; i < n; i++) {
			v[i].first = double(arr[i].value) / arr[i].weight;
			v[i].second = arr + i;
		}
		sort(v.begin(), v.end(), compare);
		double ans;
		for (int i = 0; i < n; i++) {
			if (W <= v[i].second->weight) {
				ans += W * v[i].first;
				break;
			}
			else {
				W -= v[i].second->weight;
				ans += v[i].second->value;
			}
		}
		return ans;
	}
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin >> t;
	cout << setprecision(2) << fixed;
	while (t--) {
		//size of array and weight
		int n, W;
		cin >> n >> W;

		Item arr[n];
		//value and weight of each item
		for (int i = 0; i < n; i++) {
			cin >> arr[i].value >> arr[i].weight;
		}

		//function call
		Solution ob;
		cout << ob.fractionalKnapsack(W, arr, n) << endl;
	}
	return 0;
}  // } Driver Code Ends