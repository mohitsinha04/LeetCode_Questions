class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int jumps = 1;
        int maxstep = nums[0];
        int maxpos = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(maxstep < i) {
                jumps++;
                maxstep = maxpos;
            }
            maxpos = max(maxpos, nums[i] + i);
        }
        return jumps;
    }
};
​
​
​
​
​
​
​
​
​
​
