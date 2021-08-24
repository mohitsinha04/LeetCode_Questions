class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i : nums) {
            if (hash.count(i)) 
                return true;
            hash.insert(i);
        }
        return false;
    }
};