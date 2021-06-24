class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> map;
        int winstart = 0, maxLength = 0;
        for (int winend = 0; winend < s.size(); winend++) {
            if (map.count(s[winend])) {
                winstart = max(winstart, map[s[winend]] + 1);
            }
            maxLength = max(maxLength, winend - winstart + 1);
            map[s[winend]] = winend;
        }
        return maxLength;
    }
};