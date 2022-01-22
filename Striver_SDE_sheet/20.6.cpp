/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		int curr = root->val;
		if (curr < p->val && curr < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		if (curr > p->val && curr > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		return root;
	}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) {
			swap(p, q);
		}
		TreeNode* temp = NULL;
		if (root->val < p->val && root->val < q->val) {
			temp = lowestCommonAncestor(root->right, p, q);
		}
		else if (root->val > p->val && root->val > q->val) {
			temp = lowestCommonAncestor(root->left, p, q);
		}
		if (root->val >= p->val && root->val <= q->val) {
			temp = root;
		}
		return temp;
	}
};