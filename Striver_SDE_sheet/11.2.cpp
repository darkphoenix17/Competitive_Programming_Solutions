int Solution::findMedian(vector<vector<int> > &a) {
	int n = a.size();
	int m = a[0].size();
	int lo = INT_MIN, hi = INT_MAX;
	while (lo <= hi) {
		int mid = (hi + lo) >> 1;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int l = 0, h = m - 1;
			while (l <= h) {
				int mi = (h + l) >> 1;
				if (a[i][mi] <= mid) {
					l = mi + 1;
				}
				else {
					h = mi - 1;
				}
			}
			cnt += l;
		}
		if (cnt <= (n * m) / 2) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	//cout<<lo<<endl;
	return lo;
}

int Solution::findMedian(vector<vector<int> > &a) {
	int n = a.size(), m = a[0].size();
	int mi = INT_MAX, ma = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		mi = min(mi, a[i][0]);
	}
	for (int i = 0; i < n; i++)
	{
		ma = max(ma, a[i][m - 1]);
	}
	int ind = ((n * m) + 1) / 2;
	while (mi < ma)
	{
		int mid = mi + (ma - mi) / 2;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			count = count + upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
		}
		if (count < ind)
			mi = mid + 1;
		else
			ma = mid;
	}
	return mi;
}
