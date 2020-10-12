/*
leetcode link : https://leetcode.com/problems/rotting-oranges/


In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int count = 0, ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
                if(grid[i][j] == 1)
                    count++;
            }
        }
        while(!q.empty()){
            int size = q.size();
            int currtime = 0;
            while(size--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i > 0 && grid[i-1][j] == 1){
                    count--;
                    grid[i-1][j] = 2;
                    q.push(make_pair(i-1, j));
                    currtime = 1;
                }
                if(i < grid.size()-1 && grid[i+1][j] == 1){
                    count--;
                    grid[i+1][j] = 2;
                    q.push(make_pair(i+1, j));
                    currtime = 1;
                }
                if(j < grid[0].size()-1 && grid[i][j+1] == 1){
                    count--;
                    grid[i][j+1] = 2;
                    q.push(make_pair(i, j+1));
                    currtime = 1;
                }
                if(j > 0 && grid[i][j-1] == 1){
                    count--;
                    grid[i][j-1] = 2;
                    q.push(make_pair(i, j-1));
                    currtime = 1;
                }
            }
            ans += currtime;
        }
        return count == 0 ? ans : -1;
    }
};
