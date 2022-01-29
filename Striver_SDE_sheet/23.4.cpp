//Method 1
#include<bits/stdc++.h>
bool isCyclicBfs(vector<int> adj[], int node, int par, vector<int> & vis) {
    bool ans = false;
    queue<pair<int, int>> q;
    vis[node] = 1;
    q.push({node, par});
    while (!q.empty()) {
        int cur = q.front().first;
        int pre = q.front().second;
        q.pop();
        for (auto x : adj[cur]) {
            if (vis[x] == 0) {
                q.push({x, cur});
                vis[x] = 1;
            }
            else if (vis[x] == 1 && x != pre) {
                ans = true;
                break;
            }
        }
    }
    return ans;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    vector<int> vis(n, 0);
    vector<int> adj[n];
    for (auto x : edges) {
        adj[x[0] - 1].push_back(x[1] - 1);
        adj[x[1] - 1].push_back(x[0] - 1);
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            if (isCyclicBfs(adj, i, -1, vis)) ans = ans || true;
        }
    }
    //cout<<ans<<endl;
    if (ans) return "Yes";
    else return "No";
}

//Method 2
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);

        // Create a queue for BFS
        queue<pair<int, int>> q;

        visited[s] = true;
        q.push({s, -1});

        while (!q.empty()) {

            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int>adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (checkForCycle(i, V, adj, vis)) return true;
            }
        }

        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends