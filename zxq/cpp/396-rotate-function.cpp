/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start

/**
 * Accepted
    17/17 cases passed (8 ms)
    Your runtime beats 92.64 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (7.5 MB)
 */
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() <= 1) {
            return 0;
        }

        long len = A.size();
        long sum = 0;
        long weightedSum = 0;
        for (int i = 0; i < len; ++i) {
            sum += A[i];
            weightedSum += (i * A[i]);
        }

        int ans = weightedSum;
        for (int i = len-1; i > 0; --i) {
            weightedSum += (sum - len * A[i]);
            ans = ans < weightedSum ? weightedSum : ans;
        }

        return ans;
    }
};
// @lc code=end

