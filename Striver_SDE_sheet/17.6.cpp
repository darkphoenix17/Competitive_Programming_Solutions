class Solution {
public:
	map<int, pair<int, int>> mp;

	void solve(Node* cur, int cnt, int height) {
		if (cur == NULL) return;
		if (mp.find(cnt) == mp.end()) {
			mp[cnt] = {height, cur->data};
		}
		else {
			if (mp[cnt].first > height) mp[cnt] = {height, cur->data};
		}
		if (cur->left) solve(cur->left, cnt - 1, height + 1);
		if (cur->right) solve(cur->right, cnt + 1, height + 1);
	}

	void topView(Node * root) {
		//vector<int> ans;
		solve(root, 0, 0);
		for (auto x : mp) {
			cout << x.second.second << " ";
		}
	}
}