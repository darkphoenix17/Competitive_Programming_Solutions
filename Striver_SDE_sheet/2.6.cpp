class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int j = 0; j < n / 2; j++) {
            for (int i = 0; i < n; i++) {
                swap(matrix[j][i], matrix[n - j - 1][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};