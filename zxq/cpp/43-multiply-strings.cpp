/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start

/**
 * Accepted
 *  311/311 cases passed (12 ms)
 *  Your runtime beats 35.46 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return string{"0"};
        }

        int curr = 0;
        string ans;
        int maxFigures = num1.size() + num2.size();

        for (int i = 0; i < maxFigures; ++i) {
            for (int j = 0; j <= i; ++j) {
                curr += getDigit(num1, j) * getDigit(num2, i-j);
            }
            ans.insert(0, 1, '0' + curr % 10);
            curr /= 10;
        }

        // 注意下面的细节
        if (ans[0] == '0') {
            ans.erase(ans.begin());
        }

        return ans;
    }

    int getDigit(string& num, int idx) {
        // 查找一个数 idx 位的值，0 位代表个位，以此类推
        if (idx >= num.size()) {
            return 0;
        }

        return num[num.size() - 1 - idx] - '0';
    }
};
// @lc code=end

