vector<int> NSE(int arr[], int n) {
	stack<int> s;
	vector<int> ans(n);
	unordered_map<int, int> mp;
	s.push(arr[0]);

	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}
		while (!s.empty() && s.top() > arr[i]) {
			mp[s.top()] = arr[i];
			s.pop();
		}
		s.push(arr[i]);
	}
	while (!s.empty()) {
		mp[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		ans[i] = mp[arr[i]];
		//cout << ans[i] << endl;
	}
	return ans;
}