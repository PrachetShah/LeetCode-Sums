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
    
    void inOrderTraversal(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        if(root->left){
            inOrderTraversal(root->left, ans);
        }
        ans.push_back(root->val);
        if(root->right){
            inOrderTraversal(root->right, ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> inOrder;
        
        inOrderTraversal(root, inOrder);
        
        return inOrder[k-1];
    }
};