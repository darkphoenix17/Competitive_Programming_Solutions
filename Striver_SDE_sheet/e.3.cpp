class Solution {
public:

	vector<int> z_function(string s) {
		int n = (int) s.length();
		vector<int> z(n);
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = min (r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}
		return z;
	}

	string longestPrefix(string s) {
		vector<int> v = z_function(s);
		int ans = 0;
		int n = v.size();
		for (int i = 0; i < n; i++) {
			if (i + v[i] == n) ans = max(ans, v[i]);
		}
		return s.substr(n - ans, ans);
		// for(int i=n-ans;i<n;i++) res+=s[i];
		// return res;
	}
};