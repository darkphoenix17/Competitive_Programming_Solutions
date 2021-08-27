class Solution {
public:
	bool check(vector<string> &board, int col, int row, int n) {
		int currow = row, curcol = col;
		while (row >= 0 && col >= 0) {
			if (board[row][col] == 'Q') return false;
			row--;
			col--;
		}
		row = currow;
		col = curcol;
		while (row < n && col >= 0) {
			if (board[row][col] == 'Q') return false;
			row++;
			col--;
		}
		row = currow;
		col = curcol;
		while (col >= 0) {
			if (board[row][col] == 'Q') return false;
			col--;
		}
		return true;
	}
	void solve(int col, vector<vector<string>> & ans, vector<string> &board, int n) {
		if (col == n) {
			ans.push_back(board);
			return;
		}
		for (int row = 0; row < n; row++) {
			if (check(board, col, row, n)) {
				board[row][col] = 'Q';
				solve(col + 1, ans, board, n);
				board[row][col] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<string> board(n);
		string s(n, '.');
		for (int i = 0; i < n; i++) {
			board[i] = s;
		}
		solve(0, ans, board, n);
		return ans;
	}
};