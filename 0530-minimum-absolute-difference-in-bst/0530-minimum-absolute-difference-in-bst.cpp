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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            nodes.push_back(temp->val);
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        int diff = INT_MAX;
        sort(nodes.begin(), nodes.end());
        for(int i=1; i<nodes.size(); i++){
            if(abs(nodes[i-1]-nodes[i]) < diff){
                diff = abs(nodes[i-1]-nodes[i]);
            }
        }
        cout << diff;
        return diff;
    }
};