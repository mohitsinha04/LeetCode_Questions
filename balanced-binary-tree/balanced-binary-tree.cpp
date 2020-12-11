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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return helper(root, height);
    }
    bool helper(TreeNode* root, int& height) {
        if(root == nullptr) {
            height = -1;
            return true;
        }
        int left = 0, right = 0;
        if(helper(root->left, left) && helper(root->right, right) && abs(left - right) < 2) {
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }
};
