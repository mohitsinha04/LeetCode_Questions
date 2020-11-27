        last->isKey = true;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    bool search(string word, int index, TrieNode* root) {
        for(int i = index; i < word.size() && root; i++) {
            if(word[i] != '.')
                root = root->child[word[i] - 'a'];
            else {
                TrieNode* curr = root;
                for(int j = 0; j < 26; j++) {
                    root = curr->child[j];
                    if(search(word, i + 1, root)) return true;
                }
            }
        }
        return root && root->isKey;
    }
    /*bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> child[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> child[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> isKey;
    }*/
};
​
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
