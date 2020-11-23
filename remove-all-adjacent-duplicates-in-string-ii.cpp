class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() < k) return s;
        stack<pair<int, char>> stack;
        for(int i = 0; i < s.size(); i++) {
            if(stack.empty() || stack.top().second != s[i]) stack.push({1, s[i]});
            else if(++stack.top().first >= k) stack.pop();
        }
        s = "";
        while(!stack.empty()) {
            for(int i = 0; i < stack.top().first; i++) s += stack.top().second;
            stack.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
