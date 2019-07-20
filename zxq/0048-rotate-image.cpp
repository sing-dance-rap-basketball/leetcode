/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

/*
  √ 21/21 cases passed (4 ms)
  √ Your runtime beats 86.91 % of cpp submissions
  √ Your memory usage beats 99.7 % of cpp submissions (8.8 MB)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        if (nrow <= 1) { return; }
        for (int i = 0; i < nrow / 2; ++i) {
            matrix[i].swap(matrix[nrow-1-i]);
        }
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return;
    }
};

