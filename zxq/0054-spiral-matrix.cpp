/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

/*
√ Accepted
  √ 22/22 cases passed (4 ms)
  √ Your runtime beats 70.16 % of cpp submissions
  √ Your memory usage beats 71.99 % of cpp submissions (8.5 MB)
√ Accepted
  √ 22/22 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 95.96 % of cpp submissions (8.4 MB)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        res.reserve((bottom-top+1) * (right-left+1));

        while (top < bottom && left < right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            for (int i = top+1; i < bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
            for (int i = bottom-1; i > top; --i) {
                res.push_back(matrix[i][left]);
            }
            ++left; --right;
            ++top; --bottom;
        }
        if (top == bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            } 
        }
        else if (top < bottom && left == right) {
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][left]);
            }
        }
        return res;        
    }
};

