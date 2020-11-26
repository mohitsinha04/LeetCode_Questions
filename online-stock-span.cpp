class StockSpanner {
public:
    vector<int> nums;
    stack<int> stack;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        nums.push_back(price);
        int n = nums.size();
        while(!stack.empty() && nums[i] >= nums[stack.top()]) {
            stack.pop();
        }
        int res = stack.empty() ? i + 1 : i - stack.top();
        stack.push(i);
        i++;
        return res;
    }
};
​
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
