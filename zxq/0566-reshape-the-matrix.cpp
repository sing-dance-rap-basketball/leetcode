/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

/*
    √ Accepted
    √ 56/56 cases passed (32 ms)
    √ Your runtime beats 93.33 % of cpp submissions
    √ Your memory usage beats 96 % of cpp submissions (11.6 MB)
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_r = nums.size();
        int old_c = nums[0].size();
        if (old_r * old_c != r * c) { return nums; }
        vector<vector<int>> res(r, vector<int>(c));
        int index = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                index = i * c + j;
                res[i][j] = nums[index / old_c][index % old_c];
            }
        }
        return res;
    }
};

