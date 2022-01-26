/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL) return "";
		string s;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur == NULL) s.append("#,");
			else s.append(to_string(cur->val) + ",");
			if (cur != NULL) {
				q.push(cur->left);
				q.push(cur->right);
			}
		}
		cout << s;
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.length() == 0) return NULL;
		stringstream s(data);
		string st;
		getline(s, st, ',');
		TreeNode* root = new TreeNode(stoi(st));
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			getline(s, st, ',');
			if (st == "#") {
				node->left == NULL;
			}
			else {
				TreeNode* leftNode = new TreeNode(stoi(st));
				node->left = leftNode;
				q.push(leftNode);
			}

			getline(s, st, ',');
			if (st == "#") {
				node->right == NULL;
			}
			else {
				TreeNode* rightNode = new TreeNode(stoi(st));
				node->right = rightNode;
				q.push(rightNode);
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));