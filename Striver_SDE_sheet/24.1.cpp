void dfs(int node, vector<int> & topo,  vector<int> adj[], vector<int> & vis) {
	vis[node] = 1;
	for (auto x : adj[node]) {
		if (!vis[x]) dfs(x, topo, adj, vis);
	}
	topo.push_back(node);
}

void revDfs(int node, vector<int> & vis, vector<int> transpose[], vector<int>& ans) {
	ans.push_back(node);
	vis[node] = 1;
	for (auto x : transpose[node]) {
		if (!vis[x]) revDfs(x, vis, transpose, ans);
	}
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
	vector<int> adj[n];
	for (auto x : edges) {
		adj[x[0]].push_back(x[1]);
	}
	vector<int> vis(n, 0), topo;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i, topo, adj, vis);
	}
	reverse(topo.begin(), topo.end());
//     for(auto x:topo) cout<<x<<" ";
//     cout<<endl;

	vector<int> transpose[n];
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		for (auto x : adj[i]) {
			transpose[x].push_back(i);
		}
	}
	vector<vector<int>> res;
	for (auto x : topo) {
		if (!vis[x]) {
			vector<int> ans;
			revDfs(x, vis, transpose, ans);
			res.push_back(ans);
		}
	}
	return res;
}