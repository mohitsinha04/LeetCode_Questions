class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        int start = left;
        if(nums[start] != target) return {-1, -1};
        right = nums.size() -1;
        while(left < right) {
            int mid = left + (right - left)/2 + 1;
            if(nums[mid] > target) right = mid -1;
            else left = mid;
        }
        return {start, left};
    }
};
