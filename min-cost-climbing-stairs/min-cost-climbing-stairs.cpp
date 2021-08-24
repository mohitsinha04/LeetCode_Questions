class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) return -1;
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return min(cost[0], cost[1]);
        
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i-2], cost[i-1]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};