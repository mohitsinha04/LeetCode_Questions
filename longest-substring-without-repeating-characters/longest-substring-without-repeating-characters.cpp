class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int winstart = 0, max_length = 0;
        unordered_map<char, int> map;
        for(int winend = 0; winend < s.size(); winend++) {
            if(map.count(s[winend])) {
                winstart = max(winstart, map[s[winend]] + 1);
            }
            max_length = max(max_length, winend - winstart + 1);
            map[s[winend]] = winend;
            
        }
        return max_length;
    }
};