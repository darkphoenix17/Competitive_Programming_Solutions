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
//METHOD 1
class Solution {
public:
	void getInorder(TreeNode *root, vector<int> &res) {
		if (!root)
			return;
		getInorder(root->left, res);
		res.push_back(root->val);
		getInorder(root->right, res);
	}
	bool findTarget(TreeNode* root, int k) {
		vector<int> v;
		getInorder(root, v);
		unordered_set<int> st;
		for (int i = 0; i < v.size(); i++) {
			if (st.find(k - v[i]) != st.end()) {
				return true;
			}
			else st.insert(v[i]);
		}
		return false;
	}
};


//METHOD 2
class BSTIterator {
	stack<TreeNode *> myStack;
	//reverse->true->before
	//reverse->false->next
	bool reverse;
public:
	BSTIterator(TreeNode *root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !myStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmpNode = myStack.top();
		myStack.pop();
		if (!reverse) pushAll(tmpNode->right);
		else pushAll(tmpNode->left);
		return tmpNode->val;
	}

private:
	void pushAll(TreeNode *node) {
		for (; node != NULL; ) {
			myStack.push(node);
			if (reverse == true) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (root == NULL) return false;
		BSTIterator l(root, false);
		BSTIterator r(root, true);
		int i = l.next();
		int j = r.next();
		while (i < j) {
			if (i + j == k) return true;
			else if (i + j < k) i = l.next();
			else j = r.next();
		}
		return false;
	}
};

