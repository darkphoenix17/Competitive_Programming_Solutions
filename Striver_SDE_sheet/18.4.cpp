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
	int solve(TreeNode* cur , bool &res) {
		if (cur == NULL) return 0;
		int l = solve(cur->left, res);
		int r = solve(cur->right, res);

		int temp = max(l, r) + 1;
		bool ans = abs(l - r) > 1 ? false : true;
		res = ans & res;
		return temp;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;
		bool ans = true;
		int a = solve(root, ans);
		return ans;
	}
};