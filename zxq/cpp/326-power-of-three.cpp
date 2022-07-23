/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start

/**
 * Accepted
    21038/21038 cases passed (12 ms)
    Your runtime beats 84.3 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.8 MB)
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};

/**
 * Accepted
    21038/21038 cases passed (20 ms)
    Your runtime beats 46.67 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.8 MB)
 */
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return n > 0 && 1162261467 % n == 0;
//     }
// };

// @lc code=end

