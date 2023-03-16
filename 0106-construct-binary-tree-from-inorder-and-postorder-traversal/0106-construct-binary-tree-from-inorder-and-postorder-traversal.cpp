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
    TreeNode* Tree(vector<int>& inorder, int x, int y, vector<int>& postorder, int a, int b){
        if(x>y || a>b){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[b]);
        int S = x;
        while(node->val != inorder[S]){
            S++;
        }
        node->left = Tree(inorder, x, S-1, postorder, a, a+S-x-1);
        node->right = Tree(inorder, S+1, y, postorder, a+S-x, b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1); 
    }
};