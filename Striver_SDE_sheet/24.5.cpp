class Solution {
public:
	//Using Prim's Algorithm
	/*
	    Step 1:
	    	Assuming we start with node 0, the index 0 in the key array is initialized to zero(because it is the first node in the MST). We find the index/node in the key array which has the minimum weight. We then find all its adjacent edges and pickup the the one with minimum weight.
		Step 2:
			Also at the same time we mark this node as true(indicating that it is now a part of the MST) and also set it’s parent as node ‘0’.
	    Step 3:
	    	After this, we would continue to find the one with minimum weight in the key array that is not a part of the MST(Notice that this is where we ensure that we pickup the node with minimum weight and we do not choose an edge that might cause a cycle)
		Step 4:
			We continue this process until all nodes become a part of the MST
	*/

	//For Step 3 to improve the time complexity we use min-heap
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int n, vector<vector<int>> adj[]) {
		vector<int> key(n, INT_MAX), par(n);
		vector<bool> mst(n, false);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		key[0] = 0;
		par[0] = -1;
		q.push({0, 0});
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			mst[u] = true;
			for (auto x : adj[u]) {
				int v = x[0];
				int w = x[1];
				if (mst[v] == false && w < key[v]) {
					par[v] = u;
					key[v] = w;
					q.push({w, v});
				}
			}
		}
		int ans = 0;
		for (auto x : key) ans += x;
		return ans;
	}
};