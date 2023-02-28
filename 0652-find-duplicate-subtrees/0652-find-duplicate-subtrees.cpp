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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> tripletToID;
        unordered_map<int, int> cnt;
        vector<TreeNode*> res;
        function<int(TreeNode*)> traverse = [&tripletToID, &cnt, &res,
                                             &traverse](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            string triplet = to_string(traverse(node->left)) + "," + to_string(node->val) + "," +
                            to_string(traverse(node->right));
            if (!tripletToID.count(triplet)) {
                tripletToID[triplet] = tripletToID.size() + 1;
            }
            int id = tripletToID[triplet];
            cnt[id]++;
            if (cnt[id] == 2) {
                res.push_back(node);
            }
            return id;
        };
        traverse(root);
        return res;
    }
};