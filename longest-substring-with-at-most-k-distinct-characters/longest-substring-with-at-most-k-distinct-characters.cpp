class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int winstart = 0, max_length = 0;
        if ((int)s.size()*k == 0) return 0;
        int match = 0;
        unordered_map<char, int> map;
        for(int winend = 0; winend < s.size(); winend++) {
            if(!map.count(s[winend])) 
                match++;
            while(match > k) {
                map[s[winstart]]--;
                if(map[s[winstart]] == 0) {
                    match--;
                    map.erase(s[winstart]);
                }
                winstart++;
            }
            map[s[winend]]++;
            max_length = max(max_length, winend - winstart + 1);
        }
        return max_length;
    }
};
