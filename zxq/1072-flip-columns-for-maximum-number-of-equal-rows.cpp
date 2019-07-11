/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

/*
  √ 84/84 cases passed (332 ms)
  √ Your runtime beats 36.36 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (27.3 MB)
  √ 84/84 cases passed (320 ms)
  √ Your runtime beats 36.85 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (27.4 MB)
*/
class Solution {
public:
    bool isSameType(vector<int>& row1, vector<int>& row2)
    {
        int xorSum = 0;
        int len = row1.size();
        for (int i = 0; i < len; ++i) {
            xorSum += (row1[i] ^ row2[i]);
        }
        return xorSum == 0 || xorSum == len;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        std::vector<int> count(matrix.size(), 0);
        int max = 1;
        for (int i = 0; i < matrix.size(); ++i) {
            bool isFound = false;
            for (int j = 0; j < i; ++j) {
                if (count[j] > 0) {
                    if (isSameType(matrix[j], matrix[i])) {
                        isFound = true;
                        count[j] += 1;
                        if (max < count[j]) { max = count[j]; }
                        break;
                    }
                }
            }
            if (!isFound) {
                count[i] = 1;
            }
        }
        return max;
    }
};

