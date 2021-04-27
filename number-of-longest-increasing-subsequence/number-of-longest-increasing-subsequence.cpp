class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int res = 0, max_len = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j ++) {
                if(nums[i] > nums[j]) {
                    if(len[i] == len[j] + 1) count[i] += count[j];
                    else if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }   
                }
            }
            if(max_len == len[i]) res += count[i];
            else if(max_len < len[i]) {
                max_len = len[i];
                res = count[i];
            }
        }
        return res;
    }
};
