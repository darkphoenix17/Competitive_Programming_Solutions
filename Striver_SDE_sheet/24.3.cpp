class Solution {
public:
	/*  Function to implement Dijkstra
	*   adj: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector <int> bellman_ford(int n, vector<vector<int>> adj, int s) {
		vector<int> dist(n, 100000000);
		dist[s] = 0;
		for (int i = 1; i < n; i++) { //Run for N-1 times as each node as each node can be connected to n-1 node at max so maximum distance update for each node can be n-1 only
			for (vector<int> x : adj) { // adj[node]={u,v,w}; such that u->v
				if (dist[x[0]] + x[2] < dist[x[1]]) {
					dist[x[1]] = dist[x[0]] + x[2];
				}
			}
		}
		bool flag = true;
		//No need to check for negative cycle as the given test containes no negative cycle
		/*  //Test for negative cycle
		for(vector<int> x:adj){
		    if(dist[x[0]]+x[2]<dist[x[1]]){
		        flag=false;
		        cout<<"-1";
		        break;
		    }
		}
		*/
		if (flag) return dist;
	}
};