class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> stack;
        int res = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!stack.empty() && heights[i] < heights[stack.top()]) {
                int h = heights[stack.top()];
                stack.pop();
                res = max(res, h * (i - (stack.empty() ? 0 : stack.top() + 1)));
            }
            stack.push(i);
        }
        int n = heights.size();
        while(!stack.empty()) {
            int h = heights[stack.top()];
            stack.pop();
            res = max(res, h * (n - (stack.empty() ? 0 : stack.top() + 1)));
        }
        return res;
    }
};
/*
res = 0;
2 1 5 6 2 3;
stack = 2, 
while(!stack.empty() && heights[1] < heights[stack.top()]) 
    int h = stack.top()
    stack.pop()
    res = max(res, heights[h] * (i - stack.top()));
res = max(0, 2 * (1 - 0));
res = 2;
​
stack = 1, 5, 6;
int h = stack.top(); -> 6
stack.pop();-> stack = 1, 2
res = max(res, height[h] * (4 - 3));
res = 6;
​
res = max(res, 5 * (4 - 2))
*/
