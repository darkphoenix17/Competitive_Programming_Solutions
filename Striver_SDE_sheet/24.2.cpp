//Dijkstra Algorithm
class Solution
{
public:
	//Function to find the shortest distance of all the vertices in weighted undirected graph
	//from the source vertex S.
	vector <int> dijkstra(int n, vector<vector<int>> adj[], int s) {
		//Create Min-heap  Note: by default priority_queue creates max_heap i.e. top gives highest number
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //pair {dist,node} stored in queue
		vector<int> dist(n, INT_MAX);
		dist[s] = 0; //Mark Source dist as 0
		q.push({dist[s], s});
		while (!q.empty()) {
			int cur_dist = q.top().first;
			int node = q.top().second;
			q.pop();
			for (auto x : adj[node]) {
				int tmp_dist = cur_dist + x[1];
				if (tmp_dist < dist[x[0]]) {
					q.push({tmp_dist, x[0]});
					dist[x[0]] = tmp_dist;
				}
			}
		}
		// for(auto x:dist) cout<<x<<" ";
		// cout<<"\n";
		return dist;
	}
};

//Note: To find the path to the shorted distance of v from source s
//Ref link:https://www.geeksforgeeks.org/shortest-path-in-a-directed-graph-by-dijkstras-algorithm/