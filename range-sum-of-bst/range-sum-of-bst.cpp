/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        dfs(root, L, R);
        return sum;
    }
    void dfs(TreeNode* root, int L, int R){
        if(root == NULL) return;
        if(root->val >= L && root->val <= R)
            sum += root->val;
        if (L < root->val)
            dfs(root->left, L, R);
        if (R > root->val)
            dfs(root->right, L, R);
    }
};