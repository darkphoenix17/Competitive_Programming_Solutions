/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

vector<int> leftView(Node *root)
{

	if (root == NULL) return {};
	queue <Node*> q;
	vector <int> v;

	q.push(root);
	Node* temp;
	int f = 0, count = 0;

	while (q.empty() != true)
	{
		count = q.size();
		while (count--)
		{
			temp = q.front();
			q.pop();
			if (f == 0)
			{
				v.push_back(temp->data);
			}
			f++;
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		f = 0;
	}
	return v;
}