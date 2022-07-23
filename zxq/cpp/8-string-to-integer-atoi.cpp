/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        long ans = 0;
        int sign = 1;
        
        for (; i < str.size() && str[i] == ' '; ++i); // go to the first non-empty character
        if (i == str.size()) { return 0; }

        if (str[i] == '-' || str[i] == '+') {
            if (i+1 == str.size() || !isDigit(str[i+1])) {
                return 0;
            }
            if (str[i] == '-') { 
                sign = -1; 
            }
            ++i;
        }
        if (!isDigit(str[i])) {
            return 0;
        }

        for (; i < str.size() && isDigit(str[i]); ++i) {
            ans = ans * 10 + (str[i] - '0');
            if (ans * sign >= INT_MAX) {
                return INT_MAX;
            }
            if (ans * sign <= INT_MIN) {
                return INT_MIN;
            }
        }

        return (int)ans * sign;
    }

    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
};
// @lc code=end

