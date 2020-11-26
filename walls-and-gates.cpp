class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0) return;
        queue<vector<int>> q;
        vector<vector<int>> dir{{0,1}, {0,-1}, {-1,0}, {1,0}};
        set<vector<int>> set;
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[i].size(); j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                    set.insert({i, j});
                }
            }
        }
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(auto d : dir) {
                int i = curr[0] + d[0];
                int j = curr[1] + d[1];
                
                if(i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] == -1 || set.count({i, j})) continue;
                
                rooms[i][j] = rooms[curr[0]][curr[1]] + 1;
                q.push({i, j});
                set.insert({i, j});
            }
        }
    }
};
