class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for(auto i : people) {
            res.insert(res.begin() + i[1], i);
        }
        return res;
    }
};
/*
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
[[7,0], [7,1], [6,1], [5,0], [5,0], [4,4]]*/
