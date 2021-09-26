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

//Recursive
class Solution {
public:
	TreeNode* prev;
	void solve(TreeNode* cur) {
		if (cur == NULL) return;

		solve(cur->right);
		solve(cur->left);

		cur->right = prev;
		if (cur->left) cur->left = NULL;
		prev = cur; //Update the prev to the nodes that has been checked down below recusrively each time
	}
	void flatten(TreeNode* root) {
		prev = NULL; //Consider prev to be that node after which the tree is flatten doen right
		solve(root);
	}
};

//Interative
class Solution {
public:
	void flatten(TreeNode* root) {
		stack<TreeNode*> st;
		if (root == NULL) return;
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			st.pop();

			if (cur->right) st.push(cur->right);
			if (cur->left != NULL) st.push(cur->left);

			if (!st.empty()) cur->right = st.top();
			cur->left = NULL;
		}
	}
};