/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start

/**
 * Accepted
    84/84 cases passed (56 ms)
    Your runtime beats 27.42 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (8.7 MB)
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long minimum = __INT_MAX__;
        long sum = 0;
        for (int num : nums) {
            minimum = num < minimum ? num : minimum;
            sum += num;
        }

        return sum - nums.size() * minimum;
    }
};
// @lc code=end

