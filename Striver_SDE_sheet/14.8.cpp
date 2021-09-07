class Solution
{
public:
	//Function to calculate the span of stockâ€™s price for all n days.
	vector <int> calculateSpan(int price[], int n) {
		stack<int> st;
		vector<int> ngl(n);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && price[st.top()] <= price[i]) st.pop();
			if (!st.empty()) ngl[i] = st.top();
			else ngl[i] = -1;
			st.push(i);
			//cout<<ngl[i]<<" ";
		}
		//cout<<endl;
		for (int i = 0; i < n; i++) {
			ngl[i] = i - ngl[i];
			//cout<<ngl[i]<<" ";
		}
		// cout<<endl;
		return ngl;
	}
};

//Leetcode: https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
	stack<int> st;
	vector<int> v;
	int i;
	StockSpanner() {
		i = 0;
	}
	int next(int price) {
		v.push_back(price);
		int ans;
		while (!st.empty() && v[st.top()] <= price) st.pop();
		if (!st.empty() && i) ans = i - st.top();
		else ans = i + 1;
		st.push(i);
		i++;
		return ans;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */