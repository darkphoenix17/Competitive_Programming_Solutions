class Solution {
public:
	void check(vector<vector<char>>& v, int x, int y) {
		if (x<0 or x >= v.size() or y<0 or y >= v[0].size() or v[x][y] == '0') return;
		v[x][y] = '0';
		check(v, x + 1, y); //down
		check(v, x, y + 1); //right
		check(v, x - 1, y); //up
		check(v, x, y - 1);	//left
	}
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					cnt++;
					check(grid, i, j);
				}
			}
		}
		//cout<<cnt;
		return cnt;
	}
};