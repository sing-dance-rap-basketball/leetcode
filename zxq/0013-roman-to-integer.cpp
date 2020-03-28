/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        string romanNumerals("IVXLCDM");
        int ans = 0;
        int curr = romanToInt(s[0]);
        int next;
        
        for (int i = 0; i < s.size() - 1; ++i) {
            next = romanToInt(s[i+1]);
            if (curr < next) {
                ans -= curr;
            }
            else {
                ans += curr;
            }
            curr = next;
        }
        ans += curr;

        return ans;
    }

    int romanToInt(char c) {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
        }
        return 0;
    }
};
// @lc code=end

