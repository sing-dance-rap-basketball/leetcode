/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    // Line 12: Char 22: runtime error: signed integer overflow: 1220703125 * 5 cannot be represented in type 'int' (solution.cpp)
    // Line 12: Char 22: runtime error: signed integer overflow: 1220703125 * 5 cannot be represented in type 'int' (solution.cpp)
    // SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:23:22
    // int trailingZeroes(int n) {
    //     int ans = 0;
    //     int temp = 5;
    //     while (true) {
    //         if (temp > n) {
    //             break;
    //         }
    //         else {
    //             ans += n / temp;
    //             temp *= 5;
    //         }
    //     }
    //     return ans;
    // }

    /**
     * Accepted
     *  502/502 cases passed (0 ms)
     *  Your runtime beats 100 % of cpp submissions
     *  Your memory usage beats 100 % of cpp submissions (6.1 MB)
     */
    int trailingZeroes(int n) {
        int ans = 0;
        long temp = 5;
        while (true) {
            if (temp > n) {
                break;
            }
            else {
                ans += n / temp;
                temp *= 5;
            }
        }
        return ans;
    }
};
// @lc code=end

