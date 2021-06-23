class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = nums[0], high = 0;
        for (int i : nums) {
            low = max(low, i);
            high += i;
        }
        int best = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int curr_sum = 0, count = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (curr_sum + nums[i] > mid) {
                    count++;
                    curr_sum = 0;
                }
                curr_sum += nums[i];
            }
            if (count > m) {
                low = mid + 1;
            } else 
                high = mid;
        }
        return low;
    }
};