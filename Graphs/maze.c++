

/*

Link : https://leetcode.com/problems/the-maze/

Problem Statement :-
There is a ball in a maze with empty spaces and walls. 
The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 
1 means the wall and 0 means the empty space. 
You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

*/

//Function : -

class Solution {
public:
    //for four direction (up, down, left, right)
    vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        //set for keeping track of visited nodes
        set<vector<int>> visited;
        //helper function with set
        return dfs(maze, start, destination, visited);
    }
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        //if we found our destination
        if(start == destination) return true;
        // for visited nodes
        if(visited.count(start)) return false;
        //mark the node as visited
        visited.insert(start);
        //four direction
        for(int i = 0; i < 4; i++) {
            //Go deep in dfs
            vector<int> res = go_deep(maze, start, d[i]);
            //if res is destination or recursive call for further direction, it will be true
            if(res == destination || dfs(maze, res, destination, visited)) return true;
        }
        //if there is no way to reach destination, we just returning false
        return false;
    }
  
    // For going to particular direction
    vector<int> go_deep(vector<vector<int>>& maze, vector<int>& start, vector<int>& d) {
        //add our direction
        int i = start[0] + d[0];
        int j = start[1] + d[1];
        int m = maze.size();
        int n = maze[0].size();
        // Check for wall !
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1) {
            return start;
        }
        // New start for recursive call
        vector<int> newStart = {i, j};
        // Recursive Call
        return go_deep(maze, newStart, d);
    }
};

