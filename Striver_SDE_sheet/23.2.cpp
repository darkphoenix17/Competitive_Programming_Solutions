class Solution {
public:
	//uses visit array and recursion(stack space)
	void check(vector<int>& vis, vector<int> adj[], int num, vector<int>& ans) {
		if (vis[num] == 1) return;
		vis[num] = 1;
		ans.push_back(num);
		for (auto &x : adj[num]) {
			if (vis[x] == 0) check(vis, adj, x, ans);
		}
	}
	// Function to return a list containing the DFS traversal of the graph.
	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		vector<int> visited(V, 0), ans;
		check(visited, adj, 0, ans);
		return ans;
	}
};


class Solution {
	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
		storeDfs.push_back(node);
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, vis, adj, storeDfs);
			}
		}
	}
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]) {
		vector<int> storeDfs;
		vector<int> vis(V + 1, 0);
		for (int i = 1; i <= V; i++) {
			if (!vis[i]) dfs(i, vis, adj, storeDfs);
		}
		return storeDfs;
	}
};