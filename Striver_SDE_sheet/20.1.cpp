20.1.cpp/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> q;
		if (root == NULL) return root;
		q.push(root);
		while (!q.empty()) {
			Node* pre = q.front();
			int n = q.size();
			cout << n << endl;
			while (n--) {
				Node* tmp = q.front();
				q.pop();
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
				if (tmp == pre) continue;
				pre->next = tmp;
				pre = tmp;
			}
			pre->next = NULL;
		}
		return root;
	}
};


class Solution {
public:
	void solve(Node* cur) {
		if (cur->left == NULL && cur->right == NULL) return;
		cur->left->next = cur->right;
		if (cur->next)
			cur->right->next = cur->next->left;
		else cur->right->next = NULL;
		solve(cur->left);
		solve(cur->right);
	}
	Node* connect(Node* root) {
		if (root == NULL) return NULL;
		solve(root);
		return root;
	}
};