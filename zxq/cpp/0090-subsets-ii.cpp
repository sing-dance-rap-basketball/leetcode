/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

/*
    Backtracking: 
    √ Accepted
    √ 19/19 cases passed (8 ms)
    √ Your runtime beats 86.73 % of cpp submissions
    √ Your memory usage beats 61.31 % of cpp submissions (9.4 MB)
    √ Accepted
    √ 19/19 cases passed (8 ms)
    √ Your runtime beats 86.73 % of cpp submissions
    √ Your memory usage beats 82.74 % of cpp submissions (9.2 MB)
    √ Accepted
    √ 19/19 cases passed (4 ms)
    √ Your runtime beats 99.7 % of cpp submissions
    √ Your memory usage beats 50.4 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> dupStart;
        for (int i = 0; i < nums.size();) {
            dupStart.push_back(i);
            for (i += 1; i < nums.size() && nums[i] == nums[i-1]; ++i);
        }
        vector<vector<int>> res {};
        vector<int> sub {};
        Backtrack(nums, res, sub, dupStart, 0);
        return res;
    }

    void Backtrack(const vector<int>& nums, vector<vector<int>>& res, 
                vector<int>& sub, vector<int>& dupStart, int idx) {
        res.push_back(sub);
        for (int i = idx; i < dupStart.size(); ++i) {
            int dupEnd = i+1 < dupStart.size() ? dupStart[i+1] : nums.size();
            sub.insert(sub.end(), dupEnd - dupStart[i], nums[dupStart[i]]);
            for (int j = dupStart[i]; j < dupEnd; ++j) {
                Backtrack(nums, res, sub, dupStart, i+1);
                sub.pop_back();
            }
        }
        return;
    }
};