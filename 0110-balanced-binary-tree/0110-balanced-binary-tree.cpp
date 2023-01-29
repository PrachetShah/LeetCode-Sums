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
    pair<bool, int> isBalancedFast(TreeNode* root){
        // Base Case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        // Conditions
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        bool condition = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        
        // Checking all true or not
        if(left.first && right.first && condition){
            ans.first = true;
            ans.second = max(left.second, right.second) + 1;
        }else{
            ans.first = false;
            return ans;
        }
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};