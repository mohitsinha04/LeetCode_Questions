class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            map[s[i]] = i;
        }
        int end = -1, start = 0;
        vector<int> res;
        string curr = "";
        for(int i = 0; i < s.size(); i++) {
            end = max(map[s[i]], end);
            if(end == i) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};