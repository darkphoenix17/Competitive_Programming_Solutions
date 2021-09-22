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
	int solve(TreeNode* cur , int &res) {
		if (cur == NULL) return 0;
		int l = solve(cur->left, res);
		int r = solve(cur->right, res);

		int temp = max(l, r) + 1;
		int ans = max(temp, l + r + 1);
		res = max(ans, res);
		return temp;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return 0;
		int ans = INT_MIN;
		int a = solve(root, ans);
		return ans - 1;
	}
};