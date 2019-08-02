/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

/*
    √ Accepted
    √ 28/28 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 37.72 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> res {};
        for (int i = 0; i < len; ++i) {
            int begin = i;
            for (; i+1 < len && nums[i] + 1 == nums[i+1]; ++i);
            int end = i;
            if (begin == end) {
                res.push_back(std::to_string(nums[begin]));
            }
            else {
                std::string temp = std::to_string(nums[begin]) + "->"
                                    + std::to_string(nums[end]);
                res.push_back(temp);
            }
        }
        return res;
    }
};

