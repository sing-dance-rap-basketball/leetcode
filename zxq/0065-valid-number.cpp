/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start

/**
 * Accepted
 *  1481/1481 cases passed (4 ms)
 *  Your runtime beats 70.33 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6 MB)
 */
class Solution {
public:
    bool isNumber(string s) {
        // trim
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        if (s.empty()) {
            return false;
        }

        auto found = s.find('e');
        if (found == string::npos) {
            return isInt(s) || isFloat(s);
        }
        else {
            string digits = s.substr(0, found);
            string power = s.substr(found+1);
            return (isInt(digits) || isFloat(digits)) && isInt(power);
        }

        return false;
    }

    bool isInt(string str) {
        if (str.empty()) {
            return false;
        }

        int i = 0;
        if (str[0] == '-' || str[0] == '+') {
            if (str.size() == 1) {
                return false;
            }
            i = 1;
        }

        for (; i < str.size(); ++i) {
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }
        return true;
    }

    bool isFloat(string str) {
        if (str.size() < 2) {
            return false;
        }

        int i = 0;
        if (str[0] == '-' || str[0] == '+') {
            if (str.size() < 3) {
                return false;
            }
            i = 1;
        }

        auto found = str.find('.', i);
        // .1 和 3. 都是有效的浮点数
        if (found == string::npos) {
            return false;
        }
        for (; i < str.size(); ++i) {
            if (i == found) {
                continue;
            }
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

