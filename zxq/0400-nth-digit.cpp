/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start

/**
 * Accepted
    588/588 cases passed (956 ms)
    Your runtime beats 5.03 % of cpp submissions
    Your memory usage beats 11.54 % of cpp submissions (42.6 MB)
 */
class Solution {
public:
    int findNthDigit(int n) {
        vector<int> tenPowers {1, 10, 100, 1000, 10000, 100000,
                            1000000, 10000000, 100000000};
 
        int i = 0;
        while (i < 8 && n > 9 * tenPowers[i] * (i+1)) {
            n -= 9 * tenPowers[i] * (i + 1);
            ++i;
        }

        int start = tenPowers[i];
        ++i;
        int quotient = n / i;
        int remainder = n % i;
        int target = start + quotient;
        if (remainder == 0) {
            --target;
            remainder = i;
        }
        return (target / tenPowers[i - remainder]) % 10;
    }
};
// @lc code=end

