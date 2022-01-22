class Solution {
public:
	bool check(TreeNode * cur, long long ma, long long mi) {
		if ((cur->val > mi) && (cur->val < ma)) return (cur->left ? check(cur->left, cur->val, mi) : true) && (cur->right ? check(cur->right, ma, cur->val) : true);
		else return false;

	}
	bool isValidBST(TreeNode* root) {
		TreeNode* cur = root;
		return check(root, LLONG_MAX, LLONG_MIN);
	}
};

class Solution {
public:
	bool check(TreeNode * cur, long long ma, long long mi) {
		if (cur == NULL) return true;
		if ((cur->val > mi) && (cur->val < ma)) return check(cur->left, cur->val, mi) && check(cur->right, ma, cur->val);
		else return false;

	}
	bool isValidBST(TreeNode* root) {
		TreeNode* cur = root;
		return check(root, LLONG_MAX, LLONG_MIN);
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
	bool isValidBST(TreeNode* root) {
		vector<int> inorder;
		getInorder(root, inorder);
		return is_sorted(inorder.begin(), inorder.end(), less_equal<int>());
	}
};