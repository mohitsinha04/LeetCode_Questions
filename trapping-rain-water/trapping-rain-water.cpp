class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];
        int left = 1;
        int right = height.size() - 1, res = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
            } else {
                if (maxRight < height[right]) {
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};