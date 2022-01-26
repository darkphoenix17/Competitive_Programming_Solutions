/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
	int cnt = 0, ans;
	void getInorder(Node *root, int k) {
		if (!root)
			return;
		getInorder(root->right, k);
		cnt++;
		if (cnt == k) ans = root->data;
		getInorder(root->left, k);
	}
	int kthLargest(Node *root, int k) {
		//vector<int> v;
		getInorder(root, k);
		return ans;
	}
};

class Solution
{
public:
	void getInorder(Node *root, vector<int> &res) {
		if (!root)
			return;
		getInorder(root->left, res);
		res.push_back(root->data);
		getInorder(root->right, res);
	}
	int kthLargest(Node *root, int k) {
		vector<int> v;
		getInorder(root, v);
		return v[v.size() - k];
	}
};



class Solution
{
public:
	int kthLargest(Node *root, int k) {
		stack<Node*> st;
		Node* node = root;
		int cnt = 0;
		while (true) {
			if (node != nullptr) {
				st.push(node);
				node = node->right;
			}
			else {
				if (st.empty()) {
					break;
				}
				node = st.top();
				st.pop();
				cnt++;
				if (cnt == k) return node->data;
				node = node->left;
			}
		}
		return -1;
	}
};