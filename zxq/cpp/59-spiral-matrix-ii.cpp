/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

/*
√ Accepted
  √ 20/20 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 49.81 % of cpp submissions (8.9 MB)
√ Accepted
  √ 20/20 cases passed (8 ms)
  √ Your runtime beats 14.47 % of cpp submissions
  √ Your memory usage beats 70.04 % of cpp submissions (8.9 MB)
√ Accepted
  √ 20/20 cases passed (4 ms)
  √ Your runtime beats 81.22 % of cpp submissions
  √ Your memory usage beats 82.02 % of cpp submissions (8.8 MB)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int numToFill = 1;
        while (top < bottom && left < right) {
            for (int i = left; i <= right; ++i) {
                res[top][i] = numToFill++;
            }
            for (int i = top+1; i < bottom; ++i) {
                res[i][right] = numToFill++;
            }
            for (int i = right; i >= left; --i) {
                res[bottom][i] = numToFill++;
            }
            for (int i = bottom-1; i > top; --i) {
                res[i][left] = numToFill++;
            }
            ++left; --right;
            ++top; --bottom;
        }
        if (top == bottom && left == right) {
            res[top][left] = numToFill;
        }
        return res;             
    }
};

