/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

/*
    √ Accepted
    √ 123/123 cases passed (172 ms)
    √ Your runtime beats 77.08 % of cpp submissions
    √ Your memory usage beats 33.33 % of cpp submissions (16.9 MB)
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int max_sum = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i-k] + nums[i];
            max_sum = std::max(sum, max_sum);
        }
        return max_sum * 1.0 / k;
    }
};

