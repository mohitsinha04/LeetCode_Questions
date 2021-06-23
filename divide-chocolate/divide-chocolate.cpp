class Solution {
public:
    int maximizeSweetness(vector<int>& nums, int K) {
        int left = nums[0], right = 0;
        for (int i : nums) {
            left = min(i, left);
            right += i;
        }
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int cur = 0, cuts = 0;
            for (int a : nums) {
                if ((cur += a) >= mid) {
                    cur = 0;
                    if (++cuts > K) break;
                }
            }
            if (cuts > K)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};