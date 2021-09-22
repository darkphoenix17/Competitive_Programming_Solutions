/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		if (root == NULL) return ans;
		q.push(root);
		int i = 1;
		while (!q.empty()) {
			int n = q.size();
			vector<int> v;
			while (n--) {
				TreeNode* tem = q.front();
				q.pop();
				if (tem->left) q.push(tem->left);
				if (tem->right) q.push(tem->right);
				v.push_back(tem->val);
			}
			if (!(i & 1)) reverse(v.begin(), v.end());
			ans.push_back(v);
			i++;
		}
		return ans;
	}
};