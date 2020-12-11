class Montonic {
private:
    deque<int> q;
public:
    void push(int val) {
        while(!q.empty() && q.back() < val) q.pop_back();
        q.push_back(val);
    }
    int max() {
        return q.front();
    }
    void pop(int val) {
        if(!q.empty() && q.front() == val) q.pop_front();
    }
};
​
​
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Montonic win;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k - 1) {
                win.push(nums[i]);
            } else {
                win.push(nums[i]);
                res.push_back(win.max());
                win.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};
