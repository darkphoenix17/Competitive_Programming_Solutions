//QuestionLink: https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the number of 'X' total shapes.
    vector<int> dx;
    vector<int> dy;
    int m, n;
    Solution() {
        dx = {0, 0, 1, -1};
        dy = {1, -1, 0, 0};
    }

    vector<vector<bool>> vis;

    bool isvalid(int x, int y, vector<vector<char>>& grid) {
        if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y] == 0 && grid[x][y] == 'X') {
            return 1;
        }
        return 0;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dx[i], y + dy[i], grid)) {
                dfs(x + dx[i], y + dy[i], grid);
            }
        }
    }
    int xShape(vector<vector<char>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<bool>> (m, vector<bool>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 'X') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.xShape(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends