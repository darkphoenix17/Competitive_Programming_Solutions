#include<bits/stdc++.h>
//Bfs method is to check for topological sort in the directed graph to check it the graph is acyclic or cyclic.
bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
	queue<int> q;
	vector<int> indegree(n, 0);
	vector<int> adj[n];
	for (auto x : edges) {
		adj[x.first - 1].push_back(x.second - 1);
		indegree[x.second - 1]++;
	}
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;
		for (auto x : adj[node]) {
			indegree[x]--;
			if (indegree[x] == 0) q.push(x);
		}
	}
	if (cnt == n) return false; //If cnt==n then topological sort worked fine and the graph should be acyclic.
	else return true;			//If the graph was cyclic then then all the indegree would have never been 0 and
	//the queue would be empty first and the cnt will never reach N or be less than N.

}