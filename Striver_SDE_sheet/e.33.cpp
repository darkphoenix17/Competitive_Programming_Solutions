class Solution {
public:
	bool check(int n, long long target, vector<int>& b) {
		long long curBatSum = 0;
		long long targetBatSum = n * target;
		for (auto x : b) {
			if (x < target) curBatSum += 1ll * x;
			else curBatSum += target;
			if (curBatSum >= targetBatSum) return true;
		}
		return false;
	}
	long long maxRunTime(int n, vector<int>& batteries) {
		long long high = 0, low = INT_MAX;
		for (auto x : batteries) {
			low = min(low, 1ll * x);
			high += 1ll * x;
		}
		long long ans = -1;
		while (low <= high) {
			long long mid = low + (high - low) / 2;
			if (check(n, mid, batteries)) {
				ans = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return ans;

	}
};