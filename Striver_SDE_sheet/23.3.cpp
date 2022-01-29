class Solution {
public:
	//uses queue and vis array
	vector<int> bfsOfGraph(int v, vector<int> adj[]) {
		vector<int> vis(v, 0), ans;
		queue<int> q;
		q.push(0);
		vis[0] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			ans.push_back(cur);
			for (auto &x : adj[cur]) {
				if (vis[x] == 0) {
					q.push(x);
					vis[x] = 1;
				}
			}
		}
		return ans;
	}
};