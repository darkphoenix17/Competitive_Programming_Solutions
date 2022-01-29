bool checkCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
	vis[node] = 1;
	dfsVis[node] = 1;
	for (auto x : adj[node]) {
		if (!vis[x]) {
			if (checkCycle(x, adj, vis, dfsVis)) return true;
		}
		else if (dfsVis[x]) return true;
	}
	dfsVis[node] = 0;  // BackTracking
	return false;
}

//we use an extra array of dfsVis to keep check of the cur visit in that particular dfs traversal so we can backTrack and check of alternative directed path of there is a dead end.
bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
	vector<int> adj[n];
	for (auto &p : edges) {
		adj[p.first - 1].push_back(p.second - 1); //As Edges are not zero based indexed so p.val-1
	}
	vector<int> vis(n, 0), dfsVis(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (checkCycle(i, adj, vis, dfsVis)) {
				return true;
			}
		}
	}
	return false;
}