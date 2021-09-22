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
	int maxDepth(TreeNode* root) {
		int ans = 0;
		if (root == NULL) return ans;
		queue<TreeNode*> q;
		q.push(root);
		//ans++;
		while (!q.empty()) {
			int n = q.size();
			while (n--) {
				TreeNode* tem = q.front();
				q.pop();
				if (tem->left) q.push(tem->left);
				if (tem->right) q.push(tem->right);
			}
			ans++;
		}
		return ans;
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root != nullptr)
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
		else {
			return 0;
		}
	}
};