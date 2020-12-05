class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if(low > high) return res;
        queue<long> q;
        for(int i = 1; i <= 9; i++) q.push(i);
        if(low == 0) res.push_back(0);
        while(!q.empty()) {
            long curr = q.front();
            q.pop();
            if(curr < high) {
                int last = curr % 10;
                if(last > 0) q.push(curr * 10 + last - 1);
                if(last < 9) q.push(curr * 10 + last + 1);
            }
            if(curr >= low && curr <= high) res.push_back((int)curr);
        }
        return res;
    }
};
