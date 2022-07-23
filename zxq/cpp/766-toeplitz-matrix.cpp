/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

/*
  √ 482/482 cases passed (8 ms)
  √ Your runtime beats 97.71 % of cpp submissions
  √ Your memory usage beats 51.65 % of cpp submissions (9.7 MB)
  √ 482/482 cases passed (8 ms)
  √ Your runtime beats 97.71 % of cpp submissions
  √ Your memory usage beats 93.4 % of cpp submissions (9.5 MB)
  √ 482/482 cases passed (12 ms)
  √ Your runtime beats 83.81 % of cpp submissions
  √ Your memory usage beats 84.65 % of cpp submissions (9.6 MB)
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

