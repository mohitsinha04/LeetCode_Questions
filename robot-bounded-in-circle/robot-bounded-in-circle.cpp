class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};
        int direction = 0; //0, 1, 2, 3, N, R, S, L
        int x = 0, y = 0;
        for (int i = 0; i < instructions.size(); i++) {
            if(instructions[i] == 'L') {
                direction = (direction + 3) % 4;
            } else if (instructions[i] == 'R') {
                direction = (direction + 1) % 4;
            } else {
                x += dir[direction][0];
                y += dir[direction][1];
            }
        }
        return (x == 0 && y == 0) || direction != 0;
    }
};