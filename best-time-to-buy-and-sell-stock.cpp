class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int lowest_price = prices[0], res = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                res = max(res, prices[i] - lowest_price);
            }
            lowest_price = min(prices[i], lowest_price);
        }
        return res;
    }
};
