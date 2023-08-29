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
    TreeNode* createMap(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent){
        TreeNode* result = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            TreeNode* temp =q.front();
            q.pop();
            
            if(temp->val == target){
                result = temp;
            }
            
            if(temp->left){
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right){
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return result;
    }
    int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodeToParent){
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            
            bool flag = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                // process neighbouring nodes
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag == 1){
                   ans++; 
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createMap(root, start, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};