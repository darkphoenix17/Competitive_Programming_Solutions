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
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode *cur = root;
		while (cur != NULL) {
			if (cur->left == NULL) {
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else {
				TreeNode* pre = cur->left;
				while (pre->right != NULL && pre->right != cur) {
					pre = pre->right;
				}

				if (pre->right == NULL) {
					pre->right = cur;
					cur = cur->left;
				}
				else if (pre->right == cur) {
					pre->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return ans;
	}
};