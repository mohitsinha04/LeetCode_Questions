class TrieNode {
public:
    bool iskey = false;
    TrieNode* child[26];
};
class Trie {
private:
    TrieNode* root;
    bool query(TrieNode* &lastNode, string word) {
        for(char c : word) {
            if(!lastNode->child[c-'a'])
                return false;
            lastNode = lastNode->child[c-'a'];
        }
        return true;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* lastNode = root;
        for(char c : word) {
            if(!lastNode->child[c-'a'])
                lastNode->child[c-'a'] = new TrieNode();
            lastNode = lastNode->child[c-'a'];
        }
        lastNode->iskey = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* lastNode = root;
        return query(lastNode, word) && lastNode->iskey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* lastNode = root;
        return query(lastNode, prefix);
    }
};
​
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
