/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
​
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        string leftsub = serialize(root->left);
        string rightsub = serialize(root->right);
        return to_string(root->val) + " " + leftsub + rightsub;
    }
​
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return decode(ss);
    }
    TreeNode* decode(istringstream &ss){
        string cur;
        ss >> cur;
        if(cur[0] == '#' || cur.empty())
            return NULL;
        TreeNode *root = new TreeNode(stoi(cur));
        root->left = decode(ss);
        root->right = decode(ss);
        return root;
    }
};
​
/*
#include <bits/stdc++.h>
using namespace std;
​
struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
​
TreeNode* decode(istringstream &ss) {
    string curr;
    ss >> curr;
    if(curr[0] == '#' || curr.empty())
        return nullptr;
    TreeNode* root = new TreeNode(stoi(curr));
    root->left = decode(ss);
