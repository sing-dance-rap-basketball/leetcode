/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 * 
 * You are standing at position 0 on an infinite number line. 
 * There is a goal at position target. 
 * On each move, you can either go left or right. 
 * During the n-th move (starting from 1), you take n steps.
 * Return the minimum number of steps required to reach the destination.
 */

// @lc code=start

/**
 * Accepted
    73/73 cases passed (4 ms)
    Your runtime beats 8.29 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6 MB)
 */
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 1;
        int sum = 0;
        while (true) {
            sum += n;
            if (sum < target) {
                ++n;
            } else if (sum == target) {
                break;
            } else {  // sum > target
                if ((sum - target) % 2 == 0) {
                    break;
                } else {
                    ++n;
                }
            }
        }
        return n;
    }
};
// @lc code=end

