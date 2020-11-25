class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j) {
        
        if(isValid(index, word))
            return true;
        
        if(isNotValid(board, word, index, i, j)) 
            return false;
        
        char c = board[i][j];
        board[i][j] = '.';
        
        bool isTrue = dfs(board, word, index + 1, i + 1, j) ||
            dfs(board, word, index + 1, i - 1, j) ||
            dfs(board, word, index + 1, i, j + 1) ||
            dfs(board, word, index + 1, i, j - 1);
        
        board[i][j] = c;
        return isTrue;
    }
    bool isNotValid(vector<vector<char>>& board, string word, int index, int i, int j) {
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || board[i][j] == '.') 
            return true;
        
        return false;
    }
    bool isValid(int index, string word) {
        if(index == word.size()) 
            return true;
        return false;
    }
};
