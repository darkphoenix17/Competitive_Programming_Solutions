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
		//Base case
		if (root == NULL) return NULL;
		if (root == p || root == q) return root;

		//Hypothesis
		TreeNode* lca_lft = lowestCommonAncestor(root->left, p, q);
		TreeNode* lca_rgt = lowestCommonAncestor(root->right, p, q);

		//Induction
		if (lca_lft && lca_rgt) return root; //means that both node are on the either side of the cur node stating cur node is the LCA
		return lca_lft == NULL ? lca_rgt : lca_lft; //Means that either on side has both the node and the other side returns NULL so we go to the one having both the nodes.
	}
};