class Solution {
public:
	//Function to find maximum of minimums of every window size.
	vector <int> maxOfMin(int arr[], int n) {
		vector<int> ans(n, 0), leftsmall(n, -1), rightsmall(n, n);
		stack<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
			if (!st.empty()) leftsmall[i] = st.top();
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
			if (!st.empty()) rightsmall[i] = st.top();
			st.push(i);
		}
		for (int i = 0; i < n; i++) {
			int ind = rightsmall[i] - leftsmall[i] - 2;
			ans[ind] = max(ans[ind], arr[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			ans[i] = max(ans[i], ans[i + 1]);
		}
		return ans;
	}
};