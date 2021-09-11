class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int curr = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9')
                curr = curr * 10 + (s[i] - '0');
            if(s[i] != ' ' && !isdigit(s[i]) || i == s.size() - 1) {
                if(sign == '+') 
                    stk.push(curr);
                else if(sign == '-') 
                    stk.push(-curr);
                else {
                    int num;
                    if(sign == '*') 
                        num = stk.top() * curr;
                    else
                        num = stk.top()/curr;
                    stk.pop();
                    stk.push(num);
                }
                sign = s[i];
                curr = 0;
            }
        }
        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};


