/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
​
class Solution {
public:
    unordered_map<Node*, NodeCopy*> map;
    NodeCopy* copyRandomBinaryTree(Node* root) {
        helper(root);
        pre(root);
        return map[root];
    }
    void helper(Node* root) {
        if(root == nullptr) return;
        map[root] = new NodeCopy(root->val);
        helper(root->left);
        helper(root->right);
    }
    void pre(Node* root) {
        if(root == nullptr) return;
        map[root]->left = map[root->left];
        map[root]->right = map[root->right];
        map[root]->random = map[root->random];
        pre(root->left);
        pre(root->right);
    }
};
