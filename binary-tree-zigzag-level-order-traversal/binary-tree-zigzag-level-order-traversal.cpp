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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int level = 0;
        deque<TreeNode*> q;
        q.push_front(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> current;
            if(level % 2 != 0) {
                for(int i = 0; i < size; i++) {
                    TreeNode* curr = q.front();
                    q.pop_front();
                    current.push_back(curr->val);
                    if(curr->right) q.push_back(curr->right);
                    if(curr->left) q.push_back(curr->left);
                }
            } else {
                for(int i = 0; i < size; i++) {
                    TreeNode* curr = q.back();
                    q.pop_back();
                    current.push_back(curr->val);
                    if(curr->left) q.push_front(curr->left);
                    if(curr->right) q.push_front(curr->right);
                }
            }
            res.push_back(current);
            level++;
        }
        return res;
    }
};
