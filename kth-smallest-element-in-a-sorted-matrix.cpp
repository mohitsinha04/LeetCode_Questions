class Solution {
public:
    struct numcompare {
        bool operator() (const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y){
            return x.first > y.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numcompare> minheap;
        for(int i = 0; i < n && i < k; i++)
            minheap.push({matrix[i][0], {i, 0}});
        int count = 0, res = 0;
        while(!minheap.empty()){
            auto heaptop = minheap.top();
            minheap.pop();
            res = heaptop.first;
            if(++count == k)
                break;
            heaptop.second.second++;
            
            if(heaptop.second.second < n){
                heaptop.first = matrix[heaptop.second.first][heaptop.second.second];
                minheap.push(heaptop);
            }
        }
        return res;
    }
};
