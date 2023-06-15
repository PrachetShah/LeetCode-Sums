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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans=0, level=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sumAtLevel = 0;
            level++;
            
            // Iterate over all nodes in current level
            for(int i=q.size(); i>0; --i){
                TreeNode* node = q.front();
                q.pop();
                sumAtLevel += node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            if(maxSum < sumAtLevel){
                maxSum = sumAtLevel;
                ans = level;
            }
        }
        
        return ans;
    }
};