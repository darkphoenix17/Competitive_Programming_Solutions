// Method 1
#include<bits/stdc++.h>
bool isCyclicDfs(set<int> adj[], int node, int par, vector<int> & vis) {
	if (vis[node] == 1) return true;
	vis[node] = 1;
	for (auto x : adj[node]) {
		if (x != par && isCyclicDfs(adj, x, node, vis)) return true;
	}
	return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
	vector<int> vis(n, 0);
	set<int> adj[n];
	for (auto x : edges) {
		adj[x[0] - 1].insert(x[1] - 1);
		adj[x[1] - 1].insert(x[0] - 1);
	}
	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0)
			ans = ans || isCyclicDfs(adj, i, -1, vis);
	}
	//cout<<ans<<endl;
	if (ans) return "Yes";
	else return "No";
}

//Method 2
bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			if (checkForCycle(it, node, vis, adj))
				return true;
		}
		else if (it != parent)
			return true;
	}

	return false;
}
bool isCycle(int V, vector<int>adj[]) {
	vector<int> vis(V + 1, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (checkForCycle(i, -1, vis, adj)) return true;
		}
	}

	return false;
}