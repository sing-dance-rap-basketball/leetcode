/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start

/**
 * Accepted
    69/69 cases passed (12 ms)
    Your runtime beats 70.4 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (9.4 MB)
 */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min0 = m, min1 = n;
        for (auto& op : ops) {
            if (op[0] < min0) min0 = op[0];
            if (op[1] < min1) min1 = op[1];
        }
        return min0 * min1;
    }
};
// @lc code=end

