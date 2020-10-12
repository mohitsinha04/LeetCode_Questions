/*

Link (Leetcode) : https://leetcode.com/problems/01-matrix/

Problem Statement :
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 
 */

//this is basically shortest distance problem using bfs 
class Solution {
public:
 //we have explore four directions!
    vector<vector<int>> dir{{1,0}, {-1, 0}, {0,-1}, {0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return matrix;
        queue<vector<int>> q;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 1) 
                    matrix[i][j] = -1;
                else
                    q.push({i, j}); //pushing the i and j
            }
        }
        int level = 1;
        //classic bfs
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0; k < size; k++) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for(auto d : dir) {
                    int i = d[0] + x;
                    int j = d[1] + y;
                    if(i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size() && matrix[i][j] == -1) {
                        matrix[i][j] = level;
                        q.push({i, j});
                    }
                }
            }
            level++;
        }
        return matrix;
    }
};
