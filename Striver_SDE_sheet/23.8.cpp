//Using BFS
class Solution
{
public:
	//TopoSort using Bfs is done with indegree array and queue.
	//Function to return list containing vertices in Topological order.
	vector<int> topoSortBfs(int n, vector<int> adj[]) {
		vector<int> indegree(n, 0); //initalise indegree for each node
		for (int i = 0; i < n; i++) {
			for (auto x : adj[i]) indegree[x]++;  //set indegree
		}
		vector<int> ans;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) q.push(i);  //put those in queue first whose indegree is 0 or which are independent of others
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for (auto x : adj[node]) {
				indegree[x]--;   //reduce indegree of adj node or reduce dependency as the cur node has been consider now so we can add the adj dependent node in the list when they are totally independent
				if (indegree[x] == 0) q.push(x); //if the adj dependent node becomes independent or indegree becomes 0 so we can consider it now so add in queue.
			}
		}
		return ans;
	}
};