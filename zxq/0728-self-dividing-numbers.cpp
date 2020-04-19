/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start

/**
 * Accepted
    31/31 cases passed (4 ms)
    Your runtime beats 55.5 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.3 MB)
 */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (isDividingNumbers(i)) ans.push_back(i);
        }
        return ans;
    }

    bool isDividingNumbers(int num) {
        int curr;
        
        for (int divisor = 1; divisor <= num; divisor *= 10)
        {
            curr = num / divisor % 10;
            if (curr == 0) return false;
            if (num % curr != 0) return false;
        }
        
        return true;
    }
};
// @lc code=end

