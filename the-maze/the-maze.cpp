class Solution {
public:
    vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return dfs(maze, start, destination, visited);
    }
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        if(start == destination) return true;
        if(visited.count(start)) return false;
        visited.insert(start);
        for(int i = 0; i < 4; i++) {
            vector<int> res = go_deep(maze, start, d[i]);
            if(res == destination || dfs(maze, res, destination, visited)) return true;
        }
        return false;
    }
    vector<int> go_deep(vector<vector<int>>& maze, vector<int>& start, vector<int>& d) {
        int i = start[0] + d[0];
        int j = start[1] + d[1];
        int m = maze.size();
        int n = maze[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1) {
            return start;
        }
        vector<int> newStart = {i, j};
        return go_deep(maze, newStart, d);
    }
};
