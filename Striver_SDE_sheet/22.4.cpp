vector<int> Solution::dNums(vector<int> &A, int B) {
	unordered_map<int, int> mp;
	for (int i = 0; i < B; i++) {
		mp[A[i]]++;
	}
	vector<int> ans;
	ans.push_back(mp.size());
	for (int i = 1; i <= A.size() - B; i++) {
		mp[A[i - 1]]--;
		if (mp[A[i - 1]] == 0) {
			mp.erase(A[i - 1]);
		}
		mp[A[i + B - 1]]++;
		ans.push_back(mp.size());
	}
	return ans;
}

vector<int> Solution::dNums(vector<int> &A, int B) {
	assert(B <= A.size());
	int n = A.size();
	vector<int> ret;
	unordered_map <int, int> m;
	for (int i = 0; i < n; i++) {
		//increase key
		m[A[i]]++;
		if (i - B + 1 >= 0) {

			//decrease key
			ret.push_back(m.size());
			m[A[i - B + 1]]--;

			//remove if count becomes 0
			if (m[A[i - B + 1]] == 0)m.erase(A[i - B + 1]);
		}
	}
	return ret;
}

