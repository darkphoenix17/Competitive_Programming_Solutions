class Solution {
public:
	int _mergesort(vector<int> &v, int left, int right) {
		int mid, count = 0;
		if (left < right) {
			mid = left + (right - left) / 2;
			count += _mergesort(v, left, mid);
			count += _mergesort(v, mid + 1, right);
			count += merge(v, left, mid + 1, right);
		}
		return count;
	}
	int merge(vector<int> &v, int left, int mid, int right) {
		int i, j;
		i = left;
		j = mid;
		int count = 0;
		vector<int> temp;
		for (i = left; i < mid; i++) {
			while (j <= right && v[i] > 2LL * v[j]) j++;
			count += (j - mid);
		}
		i = left;
		j = mid;
		while ((i <= mid - 1) && (j <= right)) {
			if (v[i] <= v[j]) {
				temp.push_back(v[i++]);
			}
			else {
				temp.push_back(v[j++]);
			}
		}
		while (i <= mid - 1)
			temp.push_back(v[i++]);
		while (j <= right)
			temp.push_back(v[j++]);
		for (i = left; i <= right; i++)
			v[i] = temp[i - left];
		return count;
	}

	int reversePairs(vector<int>& nums) {
		return _mergesort(nums, 0, nums.size() - 1);
	}
};