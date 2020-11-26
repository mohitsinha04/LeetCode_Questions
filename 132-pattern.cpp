class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> stack;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] < s3) return true;
            while(!stack.empty() && nums[i] > nums[stack.top()]) {
                s3 = nums[stack.top()];
                stack.pop();
            }
            stack.push(i);
        }
        return false;
    }
};
