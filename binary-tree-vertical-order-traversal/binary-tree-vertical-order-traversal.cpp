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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, vector<int>> map;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            map[curr.second].push_back(curr.first->val);
            if(curr.first->left) q.push({curr.first->left, curr.second - 1});
            if(curr.first->right) q.push({curr.first->right, curr.second + 1});
        }
        for(auto i : map) {
            res.push_back(i.second);
        }
        return res;
    }
};
