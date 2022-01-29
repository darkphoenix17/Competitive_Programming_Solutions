class Solution {
public:
	//returns true if the cycle is odd and the adjacent node have same color;
	bool bipartiteFailBfs(vector<vector<int>> &v, vector<int> & color, int node) {
		//if(bipartiteerror) return true;
		queue<int> q;
		q.push(node);
		color[node] = 1; //mark start node as color 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto x : v[cur]) {		// mark the adj node or check if the adj node is marked with the correct color
				if (color[x] == -1) {
					color[x] = 1 - color[cur];
					q.push(x);
				}
				else if (color[x] == color[cur]) { //if adj color marked is not proper as per the property of bipartite return true;
					return true;
				}
			}
		}
		return false;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n, -1);
		bool ans = true;
		for (int i = 0; i < n; i++) { //check for each individual graph
			if (color[i] == -1) {
				if (bipartiteFailBfs(graph, color, i)) ans = ans && false;  //if true means the graph can't be bipartite so ans will be false;
			}
		}
		return ans;
	}
};