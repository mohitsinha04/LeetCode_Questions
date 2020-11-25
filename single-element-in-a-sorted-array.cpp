class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left)/ 2;
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid + 1])
                    left = mid + 1;
                else 
                    right = mid;
            } else {
                if(nums[mid] == nums[mid + 1])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return nums[left];
    }
};
//[1,1,2,3,3,4,4,8,8];
 //0 1 2 3 4 5 6 7 8
