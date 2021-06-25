class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int winstart = 0, max_length = 0;
        if(s.size() < 2) return s.size();
        int match = 0;
        unordered_map<char, int> map;
        for(int winend = 0; winend < s.size(); winend++) {
            if(!map.count(s[winend])) {
                match++;
            }
            while(match > 2) {
                map[s[winstart]]--;
                if(map[s[winstart]] == 0) {
                    map.erase(s[winstart]);
                    match--;
                }
                winstart++;
            }
            map[s[winend]]++;
            max_length = max(max_length, winend - winstart + 1);
        }
        return max_length;
    }
};