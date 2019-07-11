/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

/*
  √ 49/49 cases passed (40 ms)
  √ Your runtime beats 77.21 % of cpp submissions
  √ Your memory usage beats 99.41 % of cpp submissions (8.9 MB)
  √ 49/49 cases passed (44 ms)
  √ Your runtime beats 76.1 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (8.8 MB)
  √ Your memory usage beats 85.21 % of cpp submissions (9 MB)
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len = A.size();
        int maxOverlap = 0;
        int sum = 0;
        for (int shiftX = 1-len; shiftX < len; ++shiftX) {
            for (int shiftY = 1-len; shiftY < len; ++shiftY) {
                for (int i = 0; i < len; ++i) {
                    if (i+shiftX < 0 || i+shiftX >= len) { continue; }
                    for (int j = 0; j < len; ++j) {
                        if (j+shiftY < 0 || j+shiftY >= len) { continue; }
                        sum += A[i][j] * B[i+shiftX][j+shiftY];
                    }
                }
                if (sum > maxOverlap) { maxOverlap = sum; }
                sum = 0;
            }
        }
        return maxOverlap;
    }
};

