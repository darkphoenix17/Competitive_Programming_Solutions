#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v, int mid, int cow) {
	int temp = v[0];
	int cnt = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - temp >= mid) {
			cnt++;
			temp = v[i];
		}
	}
	if (cnt >= cow) return true;
	else return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, c, ans = 0;
		cin >> n >> c;
		vector<int> v(n);
		for (int &x : v) {
			cin >> x;
		}
		sort(v.begin(), v.end());
		int lo = v[0], hi = v[n - 1];
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			//cout << mid << "Mid" << " ";
			if (check(v, mid, c)) {
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		cout << ans << endl;
	}
	// your code goes here
	return 0;
}