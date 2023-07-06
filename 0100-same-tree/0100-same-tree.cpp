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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        // Base Conditions
        if(r1==NULL && r2!=NULL){
            return false;
        }
        if(r1!=NULL && r2==NULL){
            return false;
        }
        if(r1==NULL and r2==NULL){
            return true;
        }
        
        bool left = isSameTree(r1->left, r2->left);
        bool right = isSameTree(r1->right, r2->right);
        
        bool curr = r1->val==r2->val;
        
        if(left && right && curr){
            return true;
        }
        return false;
    }
};