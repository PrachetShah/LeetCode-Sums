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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int leftHeight=0, rightHeight=0;
        TreeNode* curr = root;
        
        while(curr!=NULL){
            leftHeight++;
            curr = curr->left;
        }
        
        curr = root;
        while(curr!=NULL){
            rightHeight++;
            curr = curr->right;
        }
        
        if(leftHeight==rightHeight){
            return pow(2, leftHeight)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};