// nlog(n) approach
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int i = -1;
		while (i + 1 < n && matrix[i + 1][0] <= target) {
			i++;
		}
		if (i == -1) return false;
		auto k = find(matrix[i].begin(), matrix[i].end(), target);
		if (k == matrix[i].end()) return false;
		else return true;
	}
};

//Binary Search Approach: log(n^2) approach
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int l = -1, r = n * m, mid;
		while (l + 1 < r) {
			mid = (l + r) / 2;
			if (matrix[mid / m][mid % m] < target) {
				l = mid;
			} else r = mid;
		}
		return r < n * m && matrix[r / m][r % m] == target;
	}
};
