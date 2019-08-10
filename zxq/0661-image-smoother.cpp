/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

/*
    √ Accepted
    √ 202/202 cases passed (144 ms)
    √ Your runtime beats 84.95 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (17.5 MB)
 */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int nrow = M.size();
        int ncol = M[0].size();
        vector<vector<int>> res(nrow, vector<int>(ncol));
        if (nrow == 1 && ncol == 1) {
            res[0][0] = M[0][0];
            return res;
        }
        if (nrow == 1) {
            res[0][0] = (M[0][0] + M[0][1]) / 2;
            res[0][ncol-1] = (M[0][ncol-2] + M[0][ncol-1]) / 2;
            for (int j = 1; j < ncol-1; ++j) {
                res[0][j] = (M[0][j-1] + M[0][j] + M[0][j+1]) / 3;
            }
            return res;
        }
        if (ncol == 1) {
            res[0][0] = (M[0][0] + M[1][0]) / 2;
            res[nrow-1][0] = (M[nrow-2][0] + M[nrow-1][0]) / 2;
            for (int i = 1; i < nrow-1; ++i) {
                res[i][0] = (M[i-1][0] + M[i][0] + M[i+1][0]) / 3;
            }
            return res;
        }
        res[0][0] = (M[0][0] + M[0][1] + M[1][0] + M[1][1]) / 4;
        res[0][ncol-1] = (M[0][ncol-2] + M[0][ncol-1] + M[1][ncol-2] + M[1][ncol-1]) / 4;
        res[nrow-1][0] = (M[nrow-2][0] + M[nrow-2][1] + M[nrow-1][0] + M[nrow-1][1]) / 4;
        res[nrow-1][ncol-1] = (M[nrow-2][ncol-2] + M[nrow-2][ncol-1] + M[nrow-1][ncol-2] + M[nrow-1][ncol-1]) / 4;
        for (int j = 1; j < ncol-1; ++j) {
            res[0][j] = (M[0][j-1] + M[0][j] + M[0][j+1] + M[1][j-1] + M[1][j] + M[1][j+1]) / 6;
            res[nrow-1][j] = (M[nrow-2][j-1] + M[nrow-2][j] + M[nrow-2][j+1] + M[nrow-1][j-1] + M[nrow-1][j] + M[nrow-1][j+1]) / 6;
        }
        for (int i = 1; i < nrow-1; ++i) {
            res[i][0] = (M[i-1][0] + M[i][0] + M[i+1][0] + M[i-1][1] + M[i][1] + M[i+1][1]) / 6;
            res[i][ncol-1] = (M[i-1][ncol-2] + M[i][ncol-2] + M[i+1][ncol-2] + M[i-1][ncol-1] + M[i][ncol-1] + M[i+1][ncol-1]) / 6;
        }                    
        for (int i = 1; i < nrow-1; ++i) {
            for (int j = 1; j < ncol-1; ++j) {
                res[i][j] = (M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] 
                            + M[i][j-1] + M[i][j] + M[i][j+1]
                            + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1]) / 9;
            }
        }
        return res;
    }
};