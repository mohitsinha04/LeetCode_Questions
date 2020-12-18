class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min_so_far = INT_MAX;
        for(auto i : prices) {
            if(i < min_so_far)
                min_so_far = i;
            maxProfit = max(maxProfit, i - min_so_far);
        }
        return maxProfit;
    }
};
​
