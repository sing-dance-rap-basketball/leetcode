/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start

/**
 * Accepted
 *  401/401 cases passed (8 ms)
 *  Your runtime beats 8.1 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.3 MB)
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> umap;
        int sum = 0;
        
        while (n > 0) {
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) {
                return true;
            }
            ++umap[sum];
            if (umap[sum] > 1) {
                return false;
            }
            n = sum;
            sum = 0;
        }
        
        return false;
    }
};
// @lc code=end

