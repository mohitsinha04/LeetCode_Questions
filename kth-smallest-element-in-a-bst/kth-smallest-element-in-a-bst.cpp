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
    int kthSmallest(TreeNode* root, int k) {
        int total = helper(root);
        stack<TreeNode*> stk;
        k = total - k + 1;
        while(true){
            while(root){
                stk.push(root);
                root = root->right;
            }
            root = stk.top();
            stk.pop();
            if(--k == 0) return root->val;
            root = root->left;
        }
        return -1;
    }
    int helper(TreeNode* root) {
        if(!root) return 0;
        return 1 + helper(root->left) + helper(root->right);
    }
};
