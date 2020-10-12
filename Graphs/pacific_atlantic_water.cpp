/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> r;
        int m = matrix.size();
        if (m == 0)
            return r;
        int n = matrix[0].size();
        if (n == 0)
            return r;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n-1);

        }
        for (int j = 0; j < n; j++) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, m-1, j);
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    r.push_back({i,j});
            }
        }
        return r;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;

        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
       
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
     
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
  
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);
    }
};
