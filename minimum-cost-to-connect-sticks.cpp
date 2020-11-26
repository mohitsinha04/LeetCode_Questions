class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int total_sum = 0;
        for(int i : sticks) {
            pq.push(i);
        }
        while(pq.size() > 1) {
            int sum = 0;
            sum += pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            pq.push(sum);
            total_sum += sum;
        }
        return total_sum;
    }
};
