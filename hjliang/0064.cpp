/**
 * 64. Minimum Path Sum
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */
 
/**
 * Runtime: 8 ms, faster than 88.22% of C++ online submissions for Minimum Path Sum.
 * Memory Usage: 10.5 MB, less than 97.28% of C++ online submissions for Minimum Path Sum.
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long DP[m][n];
        DP[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            DP[i][0] = grid[i][0] + DP[i-1][0];
        }
        for (int i = 1; i < n; ++i) {
            DP[0][i] = grid[0][i] + DP[0][i-1];
        }
        
        if (m == 1)
            return DP[0][n-1];
        if (n == 1)
            return DP[n-1][0];
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) 
                DP[i][j] = grid[i][j] + min(DP[i-1][j],DP[i][j-1]);
        }
        
        return DP[m-1][n-1];
    }
};