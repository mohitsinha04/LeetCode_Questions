class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        if(nums.size() == 0) return {};
        stack<int> stack;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 || stack.empty()) stack.push(nums[i]);
            else {
                while(!stack.empty() && stack.top() > 0 && stack.top() < abs(nums[i])) stack.pop();
                if(stack.empty() || stack.top() < 0) stack.push(nums[i]);
                else if(stack.top() == abs(nums[i])) stack.pop();
            }
        }
        nums = {};
        while(!stack.empty()) {
            nums.push_back(stack.top());
            stack.pop();
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};