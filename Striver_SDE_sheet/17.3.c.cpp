/*
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

//Using Morris Traversing
//NOTE: Reverse preorder's ->left and ->right in code as [2-1-3] tree would be 2-3-1 in post order and also same in reverse of preorder.
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode *cur = root;
		while (cur != NULL) {
			if (cur->right == NULL) {
				ans.push_back(cur->val);
				cur = cur->left;
			}
			else {
				TreeNode* pre = cur->right;
				while (pre->left != NULL && pre->left != cur) {
					pre = pre->left;
				}

				if (pre->left == NULL) {
					ans.push_back(cur->val);
					pre->left = cur;
					cur = cur->right;
				}
				else if (pre->left == cur) {
					pre->left = NULL;
					cur = cur->left;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};