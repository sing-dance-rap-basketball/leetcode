/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// /*
//     O(m+n) space solution
//     √ Accepted
//     √ 159/159 cases passed (64 ms)
//     √ Your runtime beats 5.4 % of cpp submissions
//     √ Your memory usage beats 20.67 % of cpp submissions (11.6 MB)
//     √ Accepted
//     √ 159/159 cases passed (48 ms)
//     √ Your runtime beats 70.83 % of cpp submissions
//     √ Your memory usage beats 35.78 % of cpp submissions (11.6 MB)
//     √ Accepted
//     √ 159/159 cases passed (44 ms)
//     √ Your runtime beats 94.06 % of cpp submissions
//     √ Your memory usage beats 68.63 % of cpp submissions (11.5 MB)
// */
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int nrow = matrix.size();
//         int ncol = matrix[0].size();
//         vector<bool> rowFlag(nrow, true);
//         vector<bool> colFlag(ncol, true);
//         for (int i = 0; i < nrow; ++i) {
//             for (int j = 0; j < ncol; ++j) {
//                 if (matrix[i][j] == 0) {
//                     rowFlag[i] = false;
//                     colFlag[j] = false;
//                 }
//             }
//         }
//         for (int i = 0; i < nrow; ++i) {
//             if (rowFlag[i]) {
//                 for (int j = 0; j < ncol; ++j) {
//                     if (!colFlag[j]) {
//                         matrix[i][j] = 0;
//                     }
//                 }
//             }
//             else {
//                 for (int j = 0; j < ncol; ++j) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         return;
//     }
// };

/*
    constant space solution
    √ Accepted
    √ 159/159 cases passed (44 ms)
    √ Your runtime beats 94.06 % of cpp submissions
    √ Your memory usage beats 64.01 % of cpp submissions (11.5 MB)
    √ Accepted
    √ 159/159 cases passed (48 ms)
    √ Your runtime beats 70.83 % of cpp submissions
    √ Your memory usage beats 75.66 % of cpp submissions (11.4 MB)
    √ Accepted
    √ 159/159 cases passed (48 ms)
    √ Your runtime beats 70.83 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (11.2 MB)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();

        int firstZeroRow = -1;
        int firstZeroCol = -1;
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (matrix[i][j] == 0) {
                    firstZeroRow = i;
                    firstZeroCol = j;
                    break;
                }
            }
            if (firstZeroRow >= 0) { break; }
        }
        if (firstZeroRow == -1) { return; } 

        for (int i = firstZeroRow + 1; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (j != firstZeroCol && matrix[i][j] == 0) {
                    matrix[i][firstZeroCol] = 0;
                    matrix[firstZeroRow][j] = 0;
                }
            }
        }

        for (int i = 0; i < nrow; ++i) {
            if (i == firstZeroRow) { continue; }
            if (matrix[i][firstZeroCol] == 0) {
                for (int j = 0; j < ncol; ++j) {
                    matrix[i][j] = 0;
                }
            }
            else {
                for (int j = 0; j < ncol; ++j) {
                    if (matrix[firstZeroRow][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        for (int j = 0; j < ncol; ++j) {
            matrix[firstZeroRow][j] = 0;
        }
        return;
    }
};

// /*
//     Top Voted Solution
// */
// void setZeroes(vector<vector<int>>& matrix) {
//     bool firstRow = false;
//     for (unsigned int j=0; j<matrix[0].size(); j++)
//         if (matrix[0][j]==0)
//             firstRow = true;
//     for (unsigned int i=1; i<matrix.size(); i++) 
//         for (unsigned int j=0; j<matrix[0].size(); j++) 
//             if (matrix[i][j]==0)
//                 matrix[i][0] = matrix[0][j] = 0;
//     for (unsigned int i=1; i<matrix.size(); i++)
//         if (matrix[i][0]==0)
//             for (unsigned int j=0; j<matrix[0].size(); j++)
//                 matrix[i][j] = 0;
//     for (unsigned int j=0; j<matrix[0].size(); j++)
//         if(matrix[0][j]==0)
//             for (unsigned int i=0; i<matrix.size(); i++)
//                 matrix[i][j] = 0;
//     if (firstRow)
//         for (unsigned int j=0; j<matrix[0].size(); j++)
//             matrix[0][j] = 0;
// }