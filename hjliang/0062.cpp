/**
 * 62. Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Note: m and n will be at most 100
 */

/**
 * Runtime: 4 ms, faster than 67.13% of C++ online submissions for Unique Paths.
 * Memory Usage: 8.2 MB, less than 84.25% of C++ online submissions for Unique Paths.
 *
 * jiu shi wan wan
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ret = 1;
        int tmp = m > n ? n : m;
        long long a = 1, b = 1;
        for (int i = 0; i < tmp - 1; ++i) {
            a = a * (m - 1 + n - 1 - i);
            b = b * (i + 1);
        }
        ret = a/b;
        return ret;
    }
};
