class Solution {
public:
	int minimumTime(string s) {
		int n = s.length();
		vector<int> lft(n + 1), rgt(n + 1);

		if (s[0] == '1') lft[1] = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') lft[i + 1] = min(lft[i] + 2, i + 1);
			else lft[i + 1] = lft[i];
		}

		if (s[n - 1] == '1') rgt[n] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '1') rgt[i + 1] = min(rgt[i + 2] + 2, n - i);
			else rgt[i + 1] = rgt[i + 2];
		}

		// for(auto x:lft){
		//     cout<<x<<" ";
		// }
		// cout<<endl;
		// for(auto x:rgt){
		//     cout<<x<<" ";
		// }
		// cout<<endl;

		int ans = INT_MAX;
		ans = min(lft[n], rgt[1]);
		for (int i = 1; i < n; i++) {
			ans = min(ans, lft[i] + rgt[i + 1]);
		}
		return ans;
	}
};