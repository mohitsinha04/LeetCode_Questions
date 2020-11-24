class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        
        for(string s : wordDict) 
            hash.insert(s);
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string curr = s.substr(j, i - j);
                    if(hash.count(curr)) {
                        dp[i] = 1;
                        //hash.erase(curr);
                        break;
                    }
                }
            }
        }
        return dp[s.size()] == 0 ? false : true;
    }
};
