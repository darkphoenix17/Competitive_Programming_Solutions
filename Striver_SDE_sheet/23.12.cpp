class Solution {
public:
	//returns true if the cycle is odd and the adjacent node have same color;
	bool bipartiteFailDfs(vector<vector<int>> &adj, vector<int> & color, int node) {
		for (auto it : adj[node]) {
			if (color[it] == -1) {   //check if not colored
				color[it] = 1 - color[node];            // mark the adj node or check if the adj node is marked with the correct color
				if (bipartiteFailDfs(adj, color, it)) {
					return true;
				}
			} else if (color[it] == color[node]) return true;   //if colored and adj color marked is not proper as per the property of bipartite return true;
		}
		return false;
	}


	//maintian color array for the checking if the node is olored at a particular time.
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n, -1);
		//bool ans=true;
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) { //check isolated sub graphs
				color[i] = 0; // initialise the color of the node for an isolated segment of graph found.
				if (bipartiteFailDfs(graph, color, i)) return false;  //if true means the graph can't be bipartite so ans will be false;
			}
		}
		return true;
	}
};