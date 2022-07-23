/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

/*
√ Accepted
  √ 61/61 cases passed (8 ms)
  √ Your runtime beats 90.35 % of cpp submissions
  √ Your memory usage beats 89.51 % of cpp submissions (10.5 MB)
√ Accepted
  √ 61/61 cases passed (12 ms)
  √ Your runtime beats 59.46 % of cpp submissions
  √ Your memory usage beats 91.78 % of cpp submissions (10.4 MB)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n, 0);
        
        // first row
        row[0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            row[j] = row[j-1] + grid[0][j];
        }

        // row by row
        for (int i = 1; i < m; ++i) {
            row[0] = row[0] + grid[i][0];
            for (int j = 1; j < n; ++j) {
                row[j] = std::min(row[j-1], row[j]) + grid[i][j];
            }
        }

        return row.back();
    }
};

