/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

/*
    √ Accepted
    √ 726/726 cases passed (28 ms)
    √ Your runtime beats 17.45 % of cpp submissions
    √ Your memory usage beats 52.38 % of cpp submissions (13.2 MB)
    √ Accepted
    √ 726/726 cases passed (24 ms)
    √ Your runtime beats 23.08 % of cpp submissions
    √ Your memory usage beats 52.38 % of cpp submissions (13.3 MB)
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        nrow = grid.size();
        ncol = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = std::max(DFS(grid, i, j), maxArea);
                }
            }
        }
        return maxArea;
    }

private:
    int nrow = 0;
    int ncol = 0;
    int DFS(vector<vector<int>>& grid, int i, int j)
    {
        int res = 1;
        vector<int> move {-1, 0, 1, 0, -1};
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int r = i + move[k];
            int c = j + move[k+1];
            if (r >= 0 && r < nrow && c >= 0 && c < ncol && grid[r][c] == 1){
                res += DFS(grid, r, c);
            }
        }
        return res;
    }
};

