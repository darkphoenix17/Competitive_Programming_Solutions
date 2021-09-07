//Using Stack
class Solution
{
public:
	//Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int> >& M, int n) {
		stack<int> st;
		for (int i = 0; i < n; i++) st.push(i);
		while (st.size() > 1) {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			if (M[a][b] == 1) {
				st.push(b);
			}
			else if (M[b][a] == 1) {
				st.push(a);
			}
		}
		if (st.empty()) return -1;
		int c = st.top();
		st.pop();
		for (int i = 0; i < n; i++) {
			if (i != c) {
				if (M[c][i] || !M[i][c]) return -1;
			}
		}
		return c;
	}
};


//Two pointer
class Solution
{
public:
	//Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int> >& M, int n) {
		int a = 0, b = n - 1;
		while (a < b) {
			if (M[a][b] == 1) {
				a++;
			}
			else {
				b--;
			}
		}
		int c = a;
		for (int i = 0; i < n; i++) {
			if (i != c) {
				if (M[c][i] || !M[i][c]) return -1;
			}
		}
		return c;
	}
};