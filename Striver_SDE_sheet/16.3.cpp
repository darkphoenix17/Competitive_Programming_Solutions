vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int Solution::solve(string A) {
	string b = A;
	int l = A.length();
	reverse(b.begin(), b.end());
	A = A + '.' + b;
	//cout<<A;
	int M = A.length();
	vector<int> lps = prefix_function(A);
	return l - lps[M - 1];
}