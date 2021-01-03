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
    int res = 0;
    void helper(TreeNode* root, int path) {
        if(!root) return;
        path = path ^ (1 << root->val);
        if(!root->left && !root->right) {
            if((path & (path - 1)) == 0) res++;
        }
        helper(root->left, path);
        helper(root->right, path);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root, 0);
        return res;
    }
};
​
