class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for (string s : strings) {
            int offset = s[0] - 'a';
            string key = "";
            for (int i = 0; i < s.size(); i++) {
                char c = (char) s[i] - offset;
                if (c < 'a') {
                    c += 26;
                }
                key += c;
            }
            map[key].push_back(s);
        }
        for (auto i : map) {
            vector<string> curr = i.second;
            sort(curr.begin(), curr.end());
            res.push_back(curr);
        }
        return res;
    }
};