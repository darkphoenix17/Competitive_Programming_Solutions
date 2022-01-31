class Solution
{
public:
	//Using Kruskal's Algorithm which uses Disjoint Set Union for optimization

	vector<int> par;
	// 	bool comp(const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){
	// 	    return (a.first<b.first);
	// 	}
	int root(int u) {
		if (u != par[u]) {
			par[u] = root(par[u]);
		}
		return par[u];
		//return parent[u] = findPar(parent[u], parent);
	}

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int n, vector<vector<int>> adj[]) {
		vector<pair<int, pair<int, int>>> edge; //edge[i]={w,{u,v}};
		par.resize(n);
		vector<int> rank(n, 0);
		for (int i = 0; i < n; i++) par[i] = i;

		for (int i = 0; i < n; i++) {
			for (auto x : adj[i]) {
				edge.push_back(make_pair(x[1], make_pair(i, x[0])));
			}
		}
		sort(edge.begin(), edge.end());
		int ans = 0;
		for (auto x : edge) {
			int u = root(x.second.first);
			int v = root(x.second.second);
			if (u != v) {
				ans += x.first;
				if (rank[u] < rank[v]) {
					swap(u, v);
				}
				par[v] = u;
				if (rank[u] == rank[v]) rank[u]++;
			}
		}
		return ans;

	}
};