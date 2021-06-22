class TrieNode {
public:
    bool isKey = false;
    TrieNode* child[26];
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    TrieNode* getRoot() {
        return root;
    }
    Trie(vector<string>& words) {
        TrieNode* curr = root;
        for(int i = 0; i < words.size(); i++) {
            addWords(words[i]);
        }
    }
    void addWords(string& word) {
        TrieNode* lastNode = root;
        for(char c : word) {
            if(!lastNode->child[c-'a'])
                lastNode->child[c-'a'] = new TrieNode();
            lastNode = lastNode->child[c-'a'];
        }
        lastNode->isKey = true;
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* word = new Trie(words);
        TrieNode* root = word->getRoot();
        unordered_set<string> hash;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, hash, "");
            }
        }
        vector<string> res;
        for(auto i : hash) {
            res.push_back(i);
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, unordered_set<string>& hash, string curr) {
        if(i < 0 || j < 0 || j >= board[0].size() || i >= board.size() || board[i][j] == ' ')
            return;
        if(root->child[board[i][j] - 'a'] != nullptr) {
            curr = curr + board[i][j];
            root = root->child[board[i][j] - 'a'];
            if(root->isKey) hash.insert(curr);
            char c = board[i][j];
            board[i][j] = ' ';
            dfs(board, i + 1, j, root, hash, curr);
            dfs(board, i - 1, j, root, hash, curr);
            dfs(board, i, j - 1, root, hash, curr);
            dfs(board, i, j + 1, root, hash, curr);
            board[i][j] = c;
        }
       
    }   
};
