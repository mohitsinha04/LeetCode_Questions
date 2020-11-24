class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int last_most = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] + i >= last_most) last_most = i;
        }
        return last_most == 0;
    }
};
