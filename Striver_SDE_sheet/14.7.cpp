class Solution {
public:
	int ans;
	queue<pair<int, int>> q;
	void solve(vector<vector<int>> & grid) {
		if (q.empty()) {
			return;
		}
		int n = q.size();
		while (n--) {
			int x = q.front().first, y = q.front().second;
			//cout<<x<<" "<<y<<endl;
			q.pop();
			if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
				grid[x + 1][y] = 2;
				q.push({x + 1, y});
			}
			if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
				grid[x][y + 1] = 2;
				q.push({x, y + 1});
			}
			if (x - 1 >= 0 && grid[x - 1][y] == 1) {
				grid[x - 1][y] = 2;
				q.push({x - 1, y});
			}
			if (y - 1 >= 0 && grid[x][y - 1] == 1) {
				grid[x][y - 1] = 2;
				q.push({x, y - 1});
			}
		}
		ans++;
		//cout<<ans<<"-----"<<endl;
		solve(grid);
	}
	int orangesRotting(vector<vector<int>>& grid) {
		ans = -1;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 2) {
					q.push({i, j});
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					cnt++;
				}
			}
		}
		if (cnt == 0) return 0;
		solve(grid);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}
		return ans;
	}
};