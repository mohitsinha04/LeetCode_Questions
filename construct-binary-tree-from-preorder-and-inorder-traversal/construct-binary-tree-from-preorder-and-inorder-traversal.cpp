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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, inorder.size() - 1);
    }
    int preindex = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start > end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preindex++]);
        int index;
        for(int i = 0; i <= end; i++) {
            if(inorder[i] == root->val){
                index = i;
                break;
            }
        }
        root->left = helper(preorder, inorder, start, index-1);
        root->right = helper(preorder, inorder, index + 1, end);
        return root;
    }
};