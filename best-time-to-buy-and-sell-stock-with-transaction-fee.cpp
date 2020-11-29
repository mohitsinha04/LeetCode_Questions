class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(prices.size(), 0);
        int maxdiff = 0;
        int maxPdiff = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(maxdiff == 0) 
                maxdiff = - prices[i-1] - fee;
            int p1 = prices[i] + maxdiff;
            int p2 = prices[i] - prices[i-1] - fee + dp[i-1];
            int p3 = dp[i-1];
            
            dp[i] = max(p1, max(p2, p3));
            
            int newDiff = - prices[i-1] - fee + dp[i-1];
            
            if(newDiff >= maxdiff) {
                maxdiff = newDiff;
                maxPdiff = dp[i-1];
            }
        }
        return dp[prices.size() - 1];
    }
};
