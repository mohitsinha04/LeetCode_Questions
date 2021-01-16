class Solution {
public:
    vector<int> first = {0, 1, 6, 8, 9}, second = {0, 1, 9, 8, 6};
    vector<string> findStrobogrammatic(int n) 
    {
        vector<string> res;
        string s (n, '0');
        helper(res, s, 0, s.size() / 2);
        return res;
    }
    
    void helper(vector<string>& res, string& s, int digit_start, int upper_border)
    {
        if (digit_start == upper_border)
        {
            res.push_back(s);
            if (s.size() == digit_start * 2)
                return;
            s[digit_start] = '1';
            res.push_back(s);
            s[digit_start] = '8';
            res.push_back(s);
            s[digit_start] = '0';
            return;
        }
        
        int mask_start = (digit_start == 0) ? 1 : 0;  
        for (int j = mask_start; j < 5; j ++)
        {
            s[digit_start] += first[j];
            s[s.size() - 1 - digit_start] += second[j];
            helper(res, s, digit_start + 1, upper_border);
            s[digit_start] -= first[j];
            s[s.size() - 1 - digit_start] -= second[j];
        }
    }
};
