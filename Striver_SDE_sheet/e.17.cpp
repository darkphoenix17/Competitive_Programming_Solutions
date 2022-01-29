//Simplified Method
// When there is a cycle in the graph the course cannot be finished as the dependency graphs should have no cycles.
class Solution {
public:
	bool checkCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
		vis[node] = 1;
		dfsVis[node] = 1;
		for (auto x : adj[node]) {
			if (!vis[x]) {
				if (checkCycle(x, adj, vis, dfsVis)) return true;
			}
			else if (dfsVis[x]) return true;
		}
		dfsVis[node] = 0; //BackTrack
		return false;
	}

	bool isCyclic(int n, vector<int> adj[n]) {
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

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int n = numCourses;
		vector<int> adj[n];
		for (auto &p : prerequisites) {
			adj[p[0]].push_back(p[1]);
		}
		return !isCyclic(n, adj);
	}
};

//Improved Method to avoid extra Function calls
class Solution {
public:
	bool checkCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
		vis[node] = 1;
		dfsVis[node] = 1;
		for (auto x : adj[node]) {
			if (!vis[x]) {
				if (checkCycle(x, adj, vis, dfsVis)) return true;
			}
			else if (dfsVis[x]) return true;
		}
		dfsVis[node] = 0;
		return false;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int n = numCourses;
		vector<int> adj[n];
		for (auto &p : prerequisites) {
			adj[p[0]].push_back(p[1]);
		}
		vector<int> vis(n, 0), dfsVis(n, 0);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				if (checkCycle(i, adj, vis, dfsVis)) {
					return false;  // Generally return true for cycle to be found but the questions wants return false when cycle is to be found.
				}
			}
		}
		return true;
	}
};
