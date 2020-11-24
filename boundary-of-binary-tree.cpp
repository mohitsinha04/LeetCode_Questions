 * };
 */
class Solution {
public:
    void addleft(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        if(root->left) {
            res.push_back(root->val);
            addleft(root->left, res);
        } else if(root->right) {
            res.push_back(root->val);
            addleft(root->right, res);
        }
    }
    void addleaves(TreeNode* root, vector<int>& res) {
        if(!root) return;
        if(!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        addleaves(root->left, res);
        addleaves(root->right, res);
    }
    void addright(TreeNode* root, vector<int>& res) {
        if(!root) return;
        if(root->right) {
            addright(root->right, res);
            res.push_back(root->val);
        } else if(root->left) {
            addright(root->left, res);
            res.push_back(root->val);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        res.push_back(root->val);
        if(root->left) addleft(root->left, res);
        if(root->left || root->right)
            addleaves(root, res);
        if(root->right) addright(root->right, res);
        return res;
    }
};
