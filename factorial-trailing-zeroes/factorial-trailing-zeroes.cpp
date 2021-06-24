class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int five = 5;
        while (n > 0) {
            n = n /5;
            res += n;
        }
        return res;
    }
};