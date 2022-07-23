/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start

/**
 * Accepted
    15/15 cases passed (4 ms)
    Your runtime beats 52.63 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }

        int ans = 0;
        int currLen = 2;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] + A[i-2] == 2 * A[i-1]) {
                ++currLen;
                ans += (currLen - 2);
            }
            else {
                currLen = 2;
            }
        }

        return ans;
    }
};
// @lc code=end

