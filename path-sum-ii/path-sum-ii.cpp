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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, root, sum);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& curr, TreeNode* root, int sum){
        if(root == nullptr) return;
        curr.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && sum == root->val){
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        else{
            backtrack(res, curr, root->left, sum - root->val);
            backtrack(res, curr, root->right, sum - root->val);
        }
        curr.pop_back();
    }
};