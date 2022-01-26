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
	int cnt = 0, ans;
	void getInorder(TreeNode *root, int k) {
		if (!root)
			return;
		getInorder(root->left, k);
		cnt++;
		if (cnt == k) ans = root->val;
		getInorder(root->right, k);
	}
	int kthSmallest(TreeNode* root, int k) {
		getInorder(root, k);
		return ans;
	}
};

class Solution {
public:
	void getInorder(TreeNode *root, vector<int> &res) {
		if (!root)
			return;
		getInorder(root->left, res);
		res.push_back(root->val);
		getInorder(root->right, res);
	}
	int kthSmallest(TreeNode* root, int k) {
		vector<int> v;
		getInorder(root, v);
		return v[k - 1];
	}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode* node = root;
		int cnt = 0;
		while (true) {
			if (node != nullptr) {
				st.push(node);
				node = node->left;
			}
			else {
				if (st.empty()) {
					break;
				}
				node = st.top();
				st.pop();
				cnt++;
				if (cnt == k) return node->val;
				node = node->right;
			}
		}
		return -1;
	}
};