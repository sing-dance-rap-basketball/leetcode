/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

/*
    √ Accepted
    √ 23/23 cases passed (4 ms)
    √ Your runtime beats 62.35 % of cpp submissions
    √ Your memory usage beats 85.71 % of cpp submissions (8.7 MB)
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) { return; }
        int nrow = board.size(), ncol = board[0].size();
        for (int r = 0; r < nrow; ++r) {
            for (int c = 0; c < ncol; ++c) {
                int sum = 0;    // sum of neighbors' states
                
                if (r > 0) {
                    if (c > 0) { sum += board[r-1][c-1]; }
                    sum += board[r-1][c];
                    if (c+1 < ncol) { sum += board[r-1][c+1]; }
                }
                if (c > 0) { sum += board[r][c-1]; }
                if (c+1 < ncol) { sum += board[r][c+1]; }
                if (r+1 < nrow) {
                    if (c > 0) { sum += board[r+1][c-1]; }
                    sum += board[r+1][c];
                    if (c+1 < ncol) { sum += board[r+1][c+1]; }
                }

                if ((sum % 10 == 2 && board[r][c] == 1) || sum % 10 == 3) {
                    board[r][c] += 10;
                }
            }
        }
        for (int r = 0; r < nrow; ++r) {
            for (int c = 0; c < ncol; ++c) {
                board[r][c] /= 10;
            }
        }
        return;
    }
};

