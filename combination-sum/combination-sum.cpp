class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(res, curr, candidates, 0, target);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& curr, vector<int>& candidates, int start, int remain){
        if(remain < 0) return;
        else if(remain == 0){
            res.push_back(curr);
            return;
        }
        else{
            for(int i = start; i < candidates.size(); i++){
                curr.push_back(candidates[i]);
                helper(res, curr, candidates, i, remain - candidates[i]);
                curr.pop_back();
            }
        }
    }
};
