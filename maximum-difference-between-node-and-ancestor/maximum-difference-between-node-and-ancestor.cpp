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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* root, int mins, int maxs){
        if(root == nullptr) return maxs - mins;
        mins = min(mins, root->val);
        maxs = max(maxs, root->val);
        return max(dfs(root->left, mins, maxs), dfs(root->right, mins, maxs));
    }
};
