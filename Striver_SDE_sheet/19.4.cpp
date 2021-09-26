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
//Recursive Approach
class Solution {
public:
	bool check(TreeNode* curlft, TreeNode* currgt) {
		if ( (curlft == NULL) != (currgt == NULL)) return false;
		else if (curlft == NULL && currgt == NULL) return true;

		bool ans = ((curlft->val) == (currgt->val));
		if (ans == false) return ans;

		bool check1 = check(curlft->right, currgt->left);
		bool check2 = check(curlft->left, currgt->right);

		return (ans && check1 && check2);

	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return check(root->left, root->right);
	}
};

class Solution {
public:
	bool f(TreeNode *root1, TreeNode* root2) {
		if (!root1) return !root2;
		if (!root2) return !root1;
		return (root1->val == root2->val) && f(root1->left, root2->right) && f(root1->right, root2->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return f(root->left, root->right);
	}
};



//Iterative DFS Approach
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		TreeNode* r1 = root->left;
		TreeNode* r2 = root->right;
		if (r1 == NULL && r2 == NULL) return true;
		if (r1 == NULL || r2 == NULL) return false;
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(r1);
		q2.push(r2);
		while (q1.empty() == false && q2.empty() == false) {
			if (q1.size() != q2.size()) return false;
			TreeNode* cur1 = q1.front();
			q1.pop();
			TreeNode* cur2 = q2.front();
			q2.pop();

			if (cur1 == NULL && cur2 == NULL) continue;
			if (cur1 == NULL && cur2 != NULL) return false;
			if (cur1 != NULL && cur2 == NULL) return false;

			if (cur1->val != cur2->val) return false;

			if (cur1->left != NULL) q1.push(cur1->left);
			else q1.push(NULL);
			if (cur1->right != NULL) q1.push(cur1->right);
			else q1.push(NULL);

			if (cur2->right != NULL) q2.push(cur2->right);
			else q2.push(NULL);
			if (cur2->left != NULL) q2.push(cur2->left);
			else q2.push(NULL);
		}
		return (q1.size() == q2.size());
	}
};