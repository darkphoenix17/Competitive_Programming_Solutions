class Solution {
public:
	int trap(vector<int>& h) {
		int n = h.size(), ma = 0;
		vector<int> maxl(n), maxr(n);
		for (int i = 0; i < n; i++) {
			ma = max(ma, h[i]);
			maxl[i] = i == 0 ? h[i] : ma;
		}
		ma = 0;
		for (int i = n - 1; i >= 0; i--) {
			ma = max(ma, h[i]);
			maxr[i] = i == n - 1 ? h[i] : ma;
		}
		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += min(maxl[i], maxr[i]) - h[i];
		}
		return ans;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();
		int left = 0; int right = n - 1;
		int res = 0;
		int maxleft = 0, maxright = 0;

		while (left <= right) {

			if (height[left] <= height[right]) {

				if (height[left] >= maxleft) maxleft = height[left];
				else res += maxleft - height[left];

				left++;
			}
			else {

				if (height[right] >= maxright) maxright = height[right];
				else res += maxright - height[right];

				right--;
			}
		}
		return res;
	}
};