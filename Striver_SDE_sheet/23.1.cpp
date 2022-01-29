/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
	map<Node*, Node*> visited;
	Node* cloneGraph(Node* node) {
		if (!node) return node;
		// if(node->val==1 && node->neighbors.size()<1) return node;
		if (visited.find(node) != visited.end()) return visited[node];
		Node* root = new Node(node->val);
		visited[node] = root;
		for (auto elem : node->neighbors)
		{
			root->neighbors.push_back(cloneGraph(elem));
		}
		return root;
	}
};

class Solution {
public:
	unordered_map<Node*, Node*> cache;

	Node* cloneGraph(Node* node) {
		if (!node)
			return nullptr;

		if (!cache.count(node)) {
			cache[node] = new Node(node->val, node->neighbors);
			for (auto& n : cache[node]->neighbors)
				n = cloneGraph(n);
		}

		return cache[node];
	}
};