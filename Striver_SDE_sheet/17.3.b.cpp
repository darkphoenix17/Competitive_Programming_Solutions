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

//Reverse Preorder method(Not the actual answer_reverse but reverse left segment with right segment)
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> st;
		if (root == NULL) return ans;

		st.push(root);
		while (!st.empty()) {
			TreeNode* temp = st.top();
			ans.push_back(temp->val);
			st.pop();
			if (temp->left) st.push(temp->left);
			if (temp->right) st.push(temp->right);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
}



class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		if (cur == NULL) return ans;
		do {
			while (cur) {
				if (cur->right) st.push(cur->right);
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();
			st.pop();
			if (cur->right && !st.empty() && st.top() == cur->right) {
				st.pop();
				st.push(cur);
				cur = cur->right;
			}
			else {
				ans.push_back(cur->val);
				cur = NULL;
			}
		} while (!st.empty());
		return ans;
	}
};