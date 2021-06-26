class TrieNode {
public:
    bool isKey = false;
    TrieNode* child[26];
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void addWord (string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(!curr->child[c - 'a'])
                curr->child[c - 'a'] = new TrieNode();
            curr = curr->child[c - 'a'];
        }
        curr->isKey = true;
    }
    bool search (string word, int index, int count) {
        if(index >= word.size()) return count >= 2;
        
        TrieNode* curr = root;
        
        for(int i = index; i < word.size(); i++) {
            char c = word[i];
            if(!curr->child[c - 'a'])
                return false;
            curr = curr->child[c - 'a'];
            if(curr->isKey) {
                if(search(word, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict (vector<string>& words) {
        vector<string> res;
        if(words.size() == 0) 
            return res;
        for(string s : words)
            addWord(s);
        for(string s : words) {
            if(search(s, 0, 0))
                res.push_back(s);
        }
        return res;
    }
};