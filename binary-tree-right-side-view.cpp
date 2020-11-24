/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(i == 0) res.push_back(curr->val);
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
        }
        return res;
    }
};
