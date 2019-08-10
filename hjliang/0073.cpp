/**
 * 73. Set Matrix Zeroes
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 */

/**
 * Runtime: 40 ms, faster than 99.47% of C++ online submissions for Set Matrix Zeroes.
 * Memory Usage: 11.5 MB, less than 81.48% of C++ online submissions for Set Matrix Zeroes.
 * in-place 但是还需要空间 就占它自己的地……
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag = 0;

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)
                flag = 1;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
        }
        
        if (matrix[0][0] == 0)
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        
        if (flag)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};