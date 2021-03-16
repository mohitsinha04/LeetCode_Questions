class Solution {
public:
    
    //x^2 + y^2;
    
    struct numcompare {
        bool operator() (const vector<int>& a, const vector<int>& b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, numcompare> maxheap;
        
        for(auto p : points){
            maxheap.push(p);
            if(maxheap.size() > K)
                maxheap.pop();
        }
        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top());
            maxheap.pop();
        }
        return res;
    }
};