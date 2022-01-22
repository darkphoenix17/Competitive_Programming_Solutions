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
	TreeNode* constructBst(vector<int>& preorder, vector<int>& inorder, int& now, int left, int right) {
		if (left > right) return NULL;

		int i = left;
		while (i <= right) {
			if (preorder[now] == inorder[i])
				break;
			i++;
		}

		TreeNode* t = new TreeNode(preorder[now++]);
		t->left = constructBst(preorder, inorder, now, left, i - 1);
		t->right = constructBst(preorder, inorder, now, i + 1, right);
		return t;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		vector<int> inorder(preorder);
		sort(inorder.begin(), inorder.end());
		int now = 0;
		return constructBst(preorder, inorder, now, 0, inorder.size() - 1);
	}
};