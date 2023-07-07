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
    int findIndex(vector<int> arr, int start, int target){
        int i=0;
        while(arr[start+i] != target){
            i++;
        }
        return i;
    }
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int inStart, int preStart, int n){
        if(n==0){
            return NULL;
        }
        
        int element = preorder[preStart];
        TreeNode* root = new TreeNode(element);
        
         int i = findIndex( inorder, inStart, preorder[preStart] );
        
        root->left = solve( inorder, preorder, inStart, preStart+1, i );
        root->right = solve( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = solve(inorder, preorder, 0, 0, inorder.size());
        return ans;
    }
};