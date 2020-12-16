class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        vector<string> mapping;
        mapping.push_back("0");
        mapping.push_back("1");
        mapping.push_back("abc");
        mapping.push_back("def");
        mapping.push_back("ghi");
        mapping.push_back("jkl");
        mapping.push_back("mno");
        mapping.push_back("pqrs");
        mapping.push_back("tuv");
        mapping.push_back("wxyz");
        
        backtrack(res, "", digits, mapping, 0);
        return res;
    }
    void backtrack(vector<string>& res, string current, string digits, vector<string>& letters, int index) {
        if(current.size() == digits.size()) {
            res.push_back(current);
            return;
        }
        string letter = letters[digits[index] - '0'];
        
        for(int i = 0; i < letter.size(); i++) {
            backtrack(res, current + letter[i], digits, letters, index + 1);
        }
    }
};
