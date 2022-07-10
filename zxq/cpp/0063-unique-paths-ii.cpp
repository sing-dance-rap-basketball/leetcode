/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

/*
√ Accepted
  √ 43/43 cases passed (4 ms)
  √ Your runtime beats 81.31 % of cpp submissions
  √ Your memory usage beats 57.29 % of cpp submissions (9.2 MB)
√ Accepted
  √ 43/43 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 21.15 % of cpp submissions (9.4 MB)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto& mat = obstacleGrid;
        if (mat[0][0] == 1 || mat.back().back() == 1) {
            return 0;
        }
        vector<vector<long>> res(mat.size(), vector<long>(mat[0].size(), 0));
        res[0][0] = 1;
        for (int i = 1; i < mat.size(); ++i) {
            res[i][0] = mat[i][0] == 0 ? res[i-1][0] : 0;
        }
        for (int j = 1; j < mat[0].size(); ++j) {
            res[0][j] = mat[0][j] == 0 ? res[0][j-1] : 0;
        }
        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 1; j < mat[0].size(); ++j) {
                res[i][j] = (mat[i][j] == 0) ? (res[i-1][j] + res[i][j-1]) : 0;
            }
        }
        return res.back().back();
    }
};

// /*
// × Time Limit Exceeded
//   × 27/43 cases passed (N/A)
//   × testcase: '[[0,0,0,0,0,0,0, ... ,1,0,0,0]]'
//   × answer: 
//   × expected_answer: 
//   × stdout:
// */
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid, int m, int n)
//     {
//         if (grid[m][n] > 0) {
//             return 0;
//         }
//         if (m == 0) {
//             for (int i = 0; i < n; ++i) {
//                 if (grid[0][i] > 0) {
//                     return 0;
//                 }
//             }
//         }
//         else if (n == 0) {
//             for (int i = 0; i < m; ++i) {
//                 if (grid[i][0] > 0) {
//                     return 0;
//                 }
//             }
//         }
//         else {
//             if (grid[m-1][n] > 0 || grid[m][n-1] > 0) {
//                 if (grid[m-1][n] == 0) {
//                     return uniquePathsWithObstacles(grid, m-1 ,n);
//                 }
//                 else if (grid[m][n-1] == 0) {
//                     return uniquePathsWithObstacles(grid, m, n-1);
//                 }
//                 else {
//                     return 0;
//                 }
//             } 
//             else {
//                 return uniquePathsWithObstacles(grid, m-1 ,n)
//                         + uniquePathsWithObstacles(grid, m, n-1);

//             }
//         }
//         return 1;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         return uniquePathsWithObstacles(obstacleGrid, 
//                 obstacleGrid.size()-1, obstacleGrid[0].size()-1);
//     }
// };

// /*
//     Top Voted Solution
// */
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<int> cur(m, 0);
//         for (int i = 0; i < m; i++) {
//             if (!obstacleGrid[i][0])
//                 cur[i] = 1;
//             else break;
//         }
//         for (int j = 1; j < n; j++) {
//             bool flag = false;
//             if (obstacleGrid[0][j])
//                 cur[0] = 0;
//             else flag = true;
//             for (int i = 1; i < m; i++) {
//                 if (!obstacleGrid[i][j]) {
//                     cur[i] += cur[i - 1]; 
//                     if (cur[i]) flag = true;
//                 }
//                 else cur[i] = 0; 
//             }
//             if (!flag) return 0;
//         }
//         return cur[m - 1];
//     }
// };
