class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) { return 0; } 
        vector<int> tail;  // keep tail value of each possible len
        tail.push_back(nums[0]);
        for (auto n : nums) {
            if (n <= tail[0]) {
                tail[0] = n;
            } else if (n > tail.back()) { // large than the tail of current largest len 
                tail.push_back(n);
            } else {  // find smallest one which is >= n
                int left = 0; 
                int right = tail.size()-1;
                int res = left;
                while(left <= right) {
                    int mid = left + (right-left)/2;
                    if (tail[mid] >= n) {
                        res = mid;
                        right = mid-1;
                    } else { // tail[mid] < n
                        left = mid+1;
                    }
                }
                tail[res] = n;
            }
        }
        return tail.size();
    }
};