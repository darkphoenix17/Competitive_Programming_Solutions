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

//Time Complexity; O(N) where N is total numbers of node in BT
class Solution {
public:
    void solve(TreeNode* cur, int cnt, vector<int> &ans) {
        if (ans.size() < cnt) ans.push_back(cur->val);
        if (cur->right) {
            solve(cur->right, cnt + 1, ans);
        }
        if (cur->left) {
            //cur=cur->left;
            solve(cur->left, cnt + 1, ans);
        }
        else return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        solve(root, 1, ans);
        return ans;
    }
};