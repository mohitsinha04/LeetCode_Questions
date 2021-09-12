class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 0) return 0;
        int winstart = 0;
        int maxLen = 1;
        unordered_map<int, int> map;
        for (int winend = 0; winend < s.size(); winend++) {
            while (map.count(s[winend])) {
                map[s[winstart]]--;
                if (map[s[winstart]] <= 0) map.erase(s[winstart]);
                winstart++;
            }
            maxLen = max(maxLen, winend - winstart + 1);
            map[s[winend]]++;
        }
        return maxLen;
    }
};