/**
 * 63. Unique Paths II
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */

/**
 * Runtime: 4 ms, faster than 77.67% of C++ online submissions for Unique Paths II.
 * Memory Usage: 9.1 MB, less than 91.76% of C++ online submissions for Unique Paths II.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        long DP[m][n];
        memset(DP,0,m*n*sizeof(long));
        
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1)
                break;
            DP[i][0] = 1;
        }
            
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1)
                break;
            DP[0][i] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    DP[i][j] = 0;
                else
                    DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
        return DP[m-1][n-1];        
    }
};