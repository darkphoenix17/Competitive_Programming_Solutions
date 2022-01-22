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
//If Unsorted array given, Sort first.
class Solution {
public:
	TreeNode* make(int lo, int hi, vector<int>& nums) {
		if (lo == hi) return new TreeNode(nums[lo]);
		if (lo > hi) return NULL;
		int m = lo + (hi - lo) / 2;
		TreeNode* root = new TreeNode(nums[m]);
		root->right = make(m + 1, hi, nums);
		root->left = make(lo, m - 1, nums);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return NULL;
		return make(0, n - 1, nums);
	}
};

