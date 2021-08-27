class Solution {
public:
	vector<pair<int, int>> row;
	vector<pair<int, int>> col;
	int f = 0;
	bool check(int x, int y, vector<vector<char>> board, char item) {
		for (int i = row[x / 3].first; i <= row[x / 3].second; i++) {
			for (int j = col[y / 3].first; j <= col[y / 3].second; j++) {
				if (item == board[i][j]) return false;
			}
		}
		for (int i = 0; i < 9; i++) {
			if (board[x][i] == item) return false;
		}
		for (int i = 0; i < 9; i++) {
			if (board[i][y] == item) return false;
		}
		return true;
	}
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {
						if (check(i, j, board, c)) {
							board[i][j] = c;

							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}

					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		row.push_back(make_pair(0, 2));
		row.push_back(make_pair(3, 5));
		row.push_back(make_pair(6, 8));
		col = row;
		solve(board);
	}
};

class Solution {
public:
	bool solve(int i, int j, vector<vector<char>>& board, int rows[][9], int cols[][9], int cells[][3][3]) {
		if (j == board[0].size()) {
			return solve(i + 1, 0, board, rows, cols, cells);
		} else if (i == board.size()) {
			return true;
		} else if (board[i][j] != '.') {
			return solve(i, j + 1, board, rows, cols, cells);
		}
		for (int k = 1; k <= 9; k++) {
			if (rows[k][i] == 1 || cols[k][j] == 1 || cells[k][i / 3][j / 3] == 1)
				continue;

			rows[k][i] = cols[k][j] = cells[k][i / 3][j / 3] = 1;
			board[i][j] = (char)(k + '0');
			if (solve(i, j + 1, board, rows, cols, cells)) {
				return true;
			}
			rows[k][i] = cols[k][j] = cells[k][i / 3][j / 3] = 0;
			board[i][j] = '.';
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		int rows[10][9] = {};
		int cols[10][9] = {};
		int cells[10][3][3] = {};

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int k = board[i][j] - '0';
					rows[k][i] = cols[k][j] = cells[k][i / 3][j / 3] = 1;
				}
			}
		}
		solve(0, 0, board, rows, cols, cells);

	}
};