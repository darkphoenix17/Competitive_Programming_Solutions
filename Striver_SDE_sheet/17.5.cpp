//Ref: https://www.geeksforgeeks.org/bottom-view-binary-tree/
class Solution {
public:
	vector <int> bottomView(Node *root) {
		vector<int> ans;
		if (root == NULL) return ans;
		int hd = 0;
		map<int, int> mp;
		queue<pair<Node*, int>> q;
		q.push({root, hd});
		while (!q.empty()) {
			Node* temp = q.front().first;
			hd = q.front().second;
			q.pop();
			mp[hd] = temp->data;
			if (temp->left) {
				q.push({temp->left, hd - 1});
			}
			if (temp->right) {
				q.push({temp->right, hd + 1});
			}
		}
		for (auto x : mp) {
			ans.push_back(x.second);
		}
		return ans;
	}
};