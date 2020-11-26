class MonoQueue {
public:
    deque<int> q;
    void push(int val) {
        while(!q.empty() && q.back() < val)
            q.pop_back();
        q.push_back(val);
    }
    int getMax() {
        return q.front();
    }
    void pop(int val) {
        if(!q.empty() && q.front() == val)
            q.pop_front();
    }
};
​
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue maxWin;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k - 1) maxWin.push(nums[i]);
            else {
                maxWin.push(nums[i]);
                res.push_back(maxWin.getMax());
                maxWin.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
