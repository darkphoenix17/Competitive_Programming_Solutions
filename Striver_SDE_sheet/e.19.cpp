class Solution {
public:
	vector<vector<bool>> grev;
	vector<vector<int>> fin;
	vector<int> t;
	vector<int> mark;

	void dfs2(int node, int running) {
		mark[node] = running;
		fin[running].push_back(node);
		for (int i = 0; i < 26; i++) {
			if (grev[node][i] == false) continue;
			if (mark[i] == -1) dfs2(i, running);
			else if (mark[i] != running) {
				t[mark[i]] = running;
			}
		}
	}

	vector<vector<bool>> g;
	vector<int> topo;
	vector<bool> vis;

	void dfs(int node) {
		vis[node] = true;
		for (int i = 0; i < 26; i++) {
			if (g[node][i] == 0) continue;
			if (vis[i] == false) dfs(i);
		}
		topo.push_back(node);
	}

	vector<string> maxNumOfSubstrings(string s) {
		int n = s.size();
		fin.resize(26);
		g.resize(26, vector<bool>(26, false)); //initialization of the graph
		t.resize(26, -1); //initialization of the scc
		grev.resize(26, vector<bool>(26, false));

		vis.resize(26, false);

		vector<int> eps(26, -1); //end position
		vector<int> beg(26, -1); //beginning position

		for (int i = 0; i < n; i++) { //marking start and end for each alphabet
			if (beg[s[i] - 'a'] == -1) beg[s[i] - 'a'] = i;
			eps[s[i] - 'a'] = i;
		}

		for (int ch = 0; ch < 26; ch++) {
			if (beg[ch] != -1) {
				for (int i = beg[ch]; i <= eps[ch]; i++) {
					g[ch][s[i] - 'a'] = true;
					grev[s[i] - 'a'][ch] = true;
				}
			}
		}

		//finding topological sorted array
		for (int i = 0; i < 26; i++) {
			if (!vis[i] and beg[i] != -1) dfs(i);
		}
		//obtained topological sorted array
		reverse(topo.begin(), topo.end());

		for (auto x : topo) cout << x << " ";
		cout << endl;

		//finding ssc
		mark.assign(26, -1);
		int cnt = 0;
		for (auto x : topo) {
			if (mark[x] == -1) {
				dfs2(x, cnt);
				cnt++;
			}
		}
		vector<string> ans;
		for (int i = 0; i < cnt; i++) {
			if (t[i] == -1) {
				int st = INT_MAX, en = INT_MIN;
				for (auto x : fin[i]) {
					st = min(st, beg[x]);
					en = max(en, eps[x]);
				}
				ans.push_back(s.substr(st, en - st + 1));
			}
		}
		return ans;
	}

};