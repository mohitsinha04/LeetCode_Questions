//https://leetcode.com/problems/search-suggestions-system/discuss/442359/C%2B%2B-Three-Way-Solution-With-Picturearrary-sort-Trie(hash%2Barray)Trie(hash%2Bheap))
class Solution {
public:
    struct Trie {
        unordered_map<char, Trie*> next = {};
        vector<string> suggest = {};
    };
​
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //build trie tree
        Trie *root = new Trie();
        for (auto word : products) {
            Trie *ptr = root;
            for (auto c : word) {
                if (!ptr->next.count(c)) {
                    ptr->next[c] = new Trie();
                }
                ptr = ptr->next[c];
                ptr->suggest.push_back(word);
            }
        }
        //search prefix
        vector<vector<string>> result(searchWord.length());
        for (int i = 0; i < searchWord.length() && root->next.count(searchWord[i]); ++ i) {
            root = root->next[searchWord[i]];
            sort(root->suggest.begin(), root->suggest.end());
            root->suggest.resize(min(3, (int)root->suggest.size()));
            result[i] = root->suggest;
        }
        return result;
    }
};
