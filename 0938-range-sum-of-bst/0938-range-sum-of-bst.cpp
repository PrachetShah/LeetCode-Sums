class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        return  (root -> val >= L && root -> val <= H ? root -> val : 0) +  // add root's value if it lies within [L, H]
                rangeSumBST(root -> left, L, H) +   // recurse left
                rangeSumBST(root -> right, L, H);   // recurse right
    }
};