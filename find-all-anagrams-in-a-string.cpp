class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map;
        for(auto i : p) map[i]++;
        int winstart = 0, match = 0;
        vector<int> res;
        for(int winend = 0; winend < s.size(); winend++) {
            if(map.count(s[winend])) {
                map[s[winend]]--;
                if(map[s[winend]] == 0) match++;
            }
            if(map.size() == match) {
                res.push_back(winstart);
            } if(winend >= p.size() - 1) {
                if(map.count(s[winstart])) {
                    if(map[s[winstart]] == 0) match--;
                    map[s[winstart]]++;
                }
                winstart++;
            }
        }
        return res;
    }
};
