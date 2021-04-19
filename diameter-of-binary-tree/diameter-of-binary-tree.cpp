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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        maxdepth(root);
        return ans;
    }
    int maxdepth(TreeNode* root){
        if(!root) return -1;
        int lefts = maxdepth(root->left);
        int rights = maxdepth(root->right);
        ans = max(ans, lefts + rights + 2);
        return max(lefts, rights) + 1;
    }
};