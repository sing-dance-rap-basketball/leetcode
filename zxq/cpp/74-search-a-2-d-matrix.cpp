/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

/*
√ Accepted
  √ 136/136 cases passed (8 ms)
  √ Your runtime beats 95.48 % of cpp submissions
  √ Your memory usage beats 19.66 % of cpp submissions (9.9 MB)
√ Accepted
  √ 136/136 cases passed (12 ms)
  √ Your runtime beats 62.88 % of cpp submissions
  √ Your memory usage beats 90 % of cpp submissions (9.7 MB)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false;
        }

        int left = 0;
        int right = matrix.size() - 1;
        while (left < right) {
            int middle = (left + right + 1) / 2;
            if (matrix[middle][0] < target) {
                left = middle;
            }
            else if (matrix[middle][0] > target) {
                right = middle - 1;
            }
            else {  // matrix[middle][0] == target
                return true;
            }
        }

        // left must equal to right
        if (matrix[left][0] == target) {    // not needed
            return true;
        }
        int rowLoc = left;
        
        left = 0;
        right = matrix[rowLoc].size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[rowLoc][middle] == target) {
                return true;
            }
            else if (matrix[rowLoc][middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return false;
    }
};

// /*
//     Top Voted Solution
// */
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     // treat the matrix as an array, just taking care of indices
//     // [0..n*m]
//     // (row, col) -> row*n + col
//     // i -> [i/n][i%n]
//     if(matrix.empty() || matrix[0].empty())
//     {
//         return false;
//     }
//     int m = matrix.size(), n = matrix[0].size();
//     int start = 0, end = m*n - 1;
//     while(start <= end)
//     {
//         int mid = start + (end - start)/2;
//         int e = matrix[mid/n][mid%n];
//         if(target < e)
//         {
//             end = mid - 1;
//         }
//         else if(target > e)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             return true;
//         }
//     }
//     return false;
// }