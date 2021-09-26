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
	int solve(TreeNode* cur, int &ans) {
		if (cur == NULL) return 0;

		int lft = solve(cur->left, ans);
		int rgt = solve(cur->right, ans);

		int temp = ((lft < 0 && rgt < 0) ? 0 : max(lft, rgt)) + (cur->val);
		int res = max(temp, lft + rgt + (cur->val));
		ans = max(ans, res);
		return temp;
	}
	int maxPathSum(TreeNode* root) {
		int ans = INT_MIN;
		solve(root, ans);
		return ans;
	}
};