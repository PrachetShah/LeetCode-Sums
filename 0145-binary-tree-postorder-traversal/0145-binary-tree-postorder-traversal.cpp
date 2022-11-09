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
class Solution {
public:
    vector<int> ans;

    void solve(TreeNode* root) {
        if(root != NULL) {
            solve(root->left);
            solve(root->right);
            ans.push_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};