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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((p == NULL) != (q == NULL)) return false;
		if (p == NULL && q == NULL) return true;

		bool lft = isSameTree(p->left, q->left);
		bool rgt = isSameTree(p->right, q->right);

		bool temp = lft && rgt;
		bool ans = temp && (p->val == q->val);

		return ans;
	}
};


class Solution {
public:
	bool check(TreeNode* a, TreeNode* b) {
		if (a == NULL && b == NULL) return true;
		else if (a == NULL && b != NULL || b == NULL && a != NULL) return false;
		else if (a->val != b->val) return false;
		else return check(a->right, b->right) && check (a->left, b->left);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return check(p, q);
	}
};