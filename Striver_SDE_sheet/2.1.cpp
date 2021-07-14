class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		int colfirst = 1, collast = 1; //for check of first and last column
		//we will use first row excluding the corner for the column check
		//we will use first column as the row check
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0) {
					if (j == 0) {
						colfirst = 0;
					}
					else if (j == m - 1) {
						collast = 0;
					}
					else {
						matrix[0][j] = 0;
					}
					matrix[i][0] = 0;
				}
			}
		}
		//setting values for all the columns
		for (int i = 1; i < m - 1; i++) {
			if (matrix[0][i] == 0) {
				for (int j = 0; j < n; j++) {
					matrix[j][i] = 0;
				}
			}
		}
		//setting values for all the rows
		for (int i = 0; i < n; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < m; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		//checking corner columns with the two variable
		if (colfirst == 0) {
			for (int i = 0; i < n; i++) {
				matrix[i][0] = 0;
			}
		}
		if (collast == 0) {
			for (int i = 0; i < n; i++) {
				matrix[i][m - 1] = 0;
			}
		}
	}
};