/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

/*
    √ Accepted
    √ 15/15 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 87.87 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res {};
        if (numRows <= 0) { return res; }
        vector<int> tier {1};
        res.push_back(tier);
        for (int i = 2; i <= numRows; ++i) {
            tier.resize(i, 1);
            for (int j = 1; j < tier.size()-1; ++j) {
                tier[j] = res.back()[j-1] + res.back()[j];
            }
            res.push_back(tier);
        }
        return res;
    }
};

