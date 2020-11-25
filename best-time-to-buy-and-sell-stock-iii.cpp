class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int left_min = prices[0];
        int right_max = prices[prices.size() - 1];
        vector<int> left(prices.size(), 0), right(prices.size(), 0);
        
        for(int i = 1; i < prices.size(); i++) {
            left[i] = max(left[i - 1], prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        }
        for(int i = prices.size() - 2; i >= 0; i--) {
            right[i] = max(right[i+1], right_max - prices[i]);
            right_max = max(right_max, prices[i]);
        }
        int res = 0;
        for(int i = 0; i < prices.size(); i++) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
