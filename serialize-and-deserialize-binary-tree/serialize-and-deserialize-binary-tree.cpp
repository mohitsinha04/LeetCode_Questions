/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        string leftsub = serialize(root->left);
        string rightsub = serialize(root->right);
        return to_string(root->val) + " " + leftsub + rightsub;
    }

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

/*
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* decode(istringstream &ss) {
    string curr;
    ss >> curr;
    if(curr[0] == '#' || curr.empty())
        return nullptr;
    TreeNode* root = new TreeNode(stoi(curr));
    root->left = decode(ss);
    root->right = decode(ss);
    return root;
}

int main() {
	// your code goes here
	vector<int> s;
	//place your value in the form : root left right and put '#' for null
	//cin>>s;
	for(int i = 0; i < n; i++){
	    cin>>a[i];
	    s += a[i] + ' ';
	}
	cout<<s;
    istringstream ss(s);
    TreeNode* root = decode(ss);
	return 0;
}

*/
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));