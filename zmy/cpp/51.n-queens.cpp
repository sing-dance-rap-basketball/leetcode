/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
// http://www.nqueens.de/sub/Conflicts.en.html
// main anti映射到对角线上
class Solution {
    void dfs(int n, int r, vector<string> &v, vector<vector<string>> &vv, vector<int>& main, vector<int>& anti, vector<int>& columns) {
        if(r == n) vv.push_back(v);
        for(int c = 0; c<n; c++) {
            if( !main[c+r] && !anti[r+n-c-1] && !columns[c]) {
                v[r][c] = 'Q';
                main[c+r] = anti[r+n-c-1] = columns[c] = 1;
                dfs(n, r+1, v, vv, main, anti, columns);
                main[c+r] = anti[r+n-c-1] = columns[c] = 0;
                v[r][c]= '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> main(2*n), anti(2*n), columns(n);
        vector<vector<string>> results;
        vector<string> v(n, string(n, '.'));
        dfs(n, 0, v, results, main, anti, columns);
        return results;
    }
};

