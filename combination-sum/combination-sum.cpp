class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, candidates, 0, target);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int index, int target) {
        if(target == 0) {
            res.push_back(curr);
            return;
        } 
        if(target < 0) return;
        for(int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(res, curr, candidates, i, target - candidates[i]);
            curr.pop_back();
        } 
    }
};