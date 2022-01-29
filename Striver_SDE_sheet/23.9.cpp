#include<bits/stdc++.h>

void dfs(vector<int> &ans, vector<int>& vis, int node, vector<int> adj[]) {
	//if(vis[node]) return;
	vis[node] = 1;
	for (auto x : adj[node]) {
		if (!vis[x]) dfs(ans, vis, x, adj);
	}
	ans.push_back(node);
}

//in dfs the one on whom the directed dependency is included will be printed first so we have to reverse the answer or store it in stack to reverse it at last
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
	vector<int> adj[v], ans, vis(v, 0);
	for (auto x : edges) {
		adj[x[0]].push_back(x[1]);
	}
	for (int i = 0; i < v; i++) {
		if (!vis[i]) dfs(ans, vis, i, adj);
	}
//     for(auto x:ans) cout<<x<<" ";
//     cout<<endl;
	reverse(ans.begin(), ans.end());  //as the one having indegree more and no outdegree will be in the start of the the vector which should be the last so reverse it.
	return ans;
}