class Solution {
public:
	int largestRectangleArea(vector<int>& h) {
		stack<int> st;
		int n = h.size();
		vector<int> leftsmaller(n), rightsmaller(n);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && h[st.top()] >= h[i]) st.pop();
			if (!st.empty()) {
				leftsmaller[i] = st.top() + 1;
			}
			else {
				leftsmaller[i] = 0;
			}
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && h[st.top()] >= h[i]) st.pop();
			if (!st.empty()) {
				rightsmaller[i] = st.top() - 1;
			}
			else {
				rightsmaller[i] = n - 1;
			}
			st.push(i);
		}
		while (!st.empty()) st.pop();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, h[i] * (rightsmaller[i] - leftsmaller[i] + 1));
			//cout<<leftsmaller[i]<<" "<<rightsmaller[i]<<" "<<ans<<endl;
		}
		return ans;
	}
};

class Solution {
public:
	int largestRectangleArea(vector<int>& h) {
		stack<int> st;
		int maxA = 0;
		int n = h.size();
		for (int i = 0; i <= n; i++) {
			while (!st.empty() && (i == n || h[st.top()] >= h[i])) {
				int height = h[st.top()];
				st.pop();
				int width;
				if (st.empty()) width = i;
				else width = i - st.top() - 1;
				// cout << i << " " << width << " " << height << endl;
				maxA = max(maxA, width * height);
			}
			st.push(i);
		}
		return maxA;
	}
};