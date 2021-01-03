/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr) {
                if(curr == u) return q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            else 
                q.push(nullptr);
        }
        
        return nullptr;
    }
};
