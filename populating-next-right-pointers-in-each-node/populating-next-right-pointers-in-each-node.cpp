/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
​
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node* temp = nullptr;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            Node* p = q.front();
            q.pop();
            if(p != nullptr) {
                p->next = q.front();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            } else if(!q.empty()) {
                q.push(nullptr);
            }
        }
        return root;
    }
};
