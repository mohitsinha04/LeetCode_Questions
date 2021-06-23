class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = weights[0], right = 0;
        for (int i : weights) {
            left = max(i, left);
            right += i;
        }
        while (left < right) {
            int mid = left + (right - left)/2;
            int count = 1, curr_sum = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (curr_sum + weights[i] > mid) {
                    count++;
                    curr_sum = 0;
                }
                curr_sum += weights[i];
            }
            if (count > D) {
                left = mid + 1;
            } else right = mid;
        }
        return left;
    }
};