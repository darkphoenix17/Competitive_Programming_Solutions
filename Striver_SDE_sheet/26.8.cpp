class Solution {
public:
	static bool comp(Job a, Job b) {
		return a.profit > b.profit;
		//return a.dead<b.dead;
	}
	//Function to find the maximum profit and the number of jobs done.
	vector<int> JobScheduling(Job arr[], int n) {
		sort(arr, arr + n, comp);
		int ans = 0, profit = 0;
		vector<bool> v(101, false);

		for (int i = 0; i < n; i++) {
			int j = arr[i].dead;
			while (j > 0 && v[j]) j--;
			if (j > 0) {
				profit += arr[i].profit;
				ans++;
				v[j] = true;
			}
		}
		return {ans, profit};
	}
};