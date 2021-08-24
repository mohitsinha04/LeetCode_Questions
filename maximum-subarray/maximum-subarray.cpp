class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSumm = INT_MIN;
        for (int i : nums) {
            sum += i;
            maxSumm = max(maxSumm, sum);
            if (sum < 0) 
                sum = 0;
        }
        return maxSumm;
    }
};