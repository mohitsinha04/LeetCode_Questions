class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> tails;
        tails.push_back(nums[0]);
        for (int n : nums) {
            if (n <= tails[0]) tails[0] = n;
            else if (n > tails[tails.size() - 1]) {
                tails.push_back(n);
            } else {
                int left = 0, res = 0;
                int right = tails.size() - 1;
                while (left <= right) {
                    int mid = left + (right - left)/2;
                    
                    if (tails[mid] >= n) {
                        res = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                tails[res] = n;
            }
        }
        return tails.size();
    }
};