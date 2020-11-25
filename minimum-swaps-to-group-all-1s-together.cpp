class Solution {
public:
    int minSwaps(vector<int>& data) {
        int left = 0, right = 0, total_ones = 0, max_len = 0, curr_ones = 0;
        for(int i : data) total_ones += i;
        while(right < data.size()) {
            curr_ones += data[right++];
            if(right - left > total_ones) {
                curr_ones -= data[left++];
            }
            max_len = max(curr_ones, max_len);
        }
        return total_ones - max_len;
    }
};
