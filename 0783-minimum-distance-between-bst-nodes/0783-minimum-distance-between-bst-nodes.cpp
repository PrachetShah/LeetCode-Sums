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
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            nodes.push_back(temp->val);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        // for(int i=0; i<nodes.size(); i++){
        //     cout<< nodes[i] << " ";
        // }
        sort(nodes.begin(), nodes.end());
        int min_diff = INT_MAX;
        for(int i=0; i<nodes.size()-1; i++){
            if(nodes[i+1] - nodes[i] < min_diff){
                min_diff = nodes[i+1] - nodes[i];
            }
        }
        return min_diff;
    }
};