class Solution {
public:
	string getPermutation(int n, int k) {
		int fact = 1;
		vector<int> st;
		for (int i = 1; i < n; i++) {
			fact = fact * i;
			st.push_back(i);
		}
		st.push_back(n);
		string ans = "";
		k = k - 1;
		while (true) {
			ans = ans + to_string(st[k / fact]);
			st.erase(st.begin() + k / fact);
			if (st.size() == 0) {
				break;
			}

			k = k % fact;
			fact = fact / st.size();
		}
		return ans;
	}
};

class Solution {
public:
	string getPermutation(int n, int k) {
		string s = "";
		for (int i = 0; i < n; i++) {
			s += '1' + i;
		}
		k--;
		while (k--) {
			next_permutation(s.begin(), s.end());
		}
		return s;
	}
};