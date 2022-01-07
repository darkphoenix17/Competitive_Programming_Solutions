class Solution {
public:
	int networkBecomesIdle(vector<vector<int>>& ed, vector<int>& p) {   //p=patience  // ed=edges
		int n = p.size();
		vector<int> dist(n, 0);
		vector<bool> vis(n, false);
		vector<vector<int>> v(n);
		for (auto x : ed) {
			v[x[0]].push_back(x[1]);
			v[x[1]].push_back(x[0]);
		}
		queue<int> q;
		q.push(0);
		vis[0] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int x : v[u]) {
				if (!vis[x]) {
					q.push(x);
					vis[x] = true;
					dist[x] = 1 + dist[u];
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			int trvl = 2 * dist[i];
			int ext = (trvl - 1) / p[i];
			int rem = trvl - ext * p[i];
			trvl = trvl * 2 - rem;
			ans = max(ans, trvl);
		}
		return ans + 1;
	}
};