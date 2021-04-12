class Solution {
public:
    int longestPalindromeSubseq(string s) {
       vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        
        for(int l = 2; l <= s.size(); l++) {
            for(int i = 0; i < s.size() - l + 1; i++) {
                int j = i + l - 1;
                //if(l == 2 && s[i] == s[j])
                  //  dp[i][j] = 2;
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};

