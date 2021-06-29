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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> map;
        map_to_parent(map, root, NULL);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> hash;
        hash.insert(target);
        q.push(target);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            if(level == K) {
                return helper(q);
            }
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !hash.count(curr->left)) {
                    q.push(curr->left);
                    hash.insert(curr->left);
                }
                if(curr->right && !hash.count(curr->right)) {
                    q.push(curr->right);
                    hash.insert(curr->right);
                }
                TreeNode* parent = map[curr];
                if(parent && !hash.count(parent)){
                    hash.insert(parent);
                    q.push(parent);
                }
            }
            level++;
        }
        return {};
    }
    void map_to_parent(unordered_map<TreeNode*, TreeNode*>& map, TreeNode* root, TreeNode* parent) {
        if(root == nullptr) return;
        map[root] = parent;
        map_to_parent(map, root->left, root);
        map_to_parent(map, root->right, root);
    }
    vector<int> helper(queue<TreeNode*>& q) {
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};