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
    int rob(TreeNode* root) {
        int lc, rc;
        return dfs (root, lc, rc);
    }
    int dfs (TreeNode* root, int& lc, int& rc) {
        if(!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        lc = dfs(root->left, ll, lr);
        rc = dfs(root->right, rl, rr);
        
        return max(ll + rr + lr + rl + root->val, lc + rc);
    }
};