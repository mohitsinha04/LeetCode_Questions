class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0) return {};
        stack<int> stack;
        for(int i = 0; i < T.size(); i++) {
            while(!stack.empty() && T[i] > T[stack.top()]) {
                T[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()) {
            T[stack.top()] = 0;
            stack.pop();
        }
        return T;
    }
};
