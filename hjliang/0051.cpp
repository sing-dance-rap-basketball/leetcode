/**
 * 51. N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 */

/*
 * Runtime: 4 ms, faster than 98.11% of C++ online submissions for N-Queens.
 * Memory Usage: 10.6 MB, less than 35.50% of C++ online submissions for N-Queens.
 * 有点分不清回溯和DFS
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        
        int *pos = new int[n];
        findQueens(n,0,pos,ret);
        return ret;
    }
    
    void findQueens(int n,int row,int *pos,vector<vector<string>> &ret) {
        if (row == n) {
            vector<string> tmp;
            for (int i = 0; i < n; ++i) {
                string str_tmp(n,'.');
                str_tmp[pos[i]] = 'Q'; 
                tmp.push_back(str_tmp);
            }
            ret.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            int j;
            for (j = 0; j < row; ++j) {
                if (i == pos[j] || abs(row - j) == abs(i - pos[j]))
                    break;
            }
            if (j == row) {
                pos[row] = i;
                findQueens(n,row+1,pos,ret);
            }
        }
        
    }
};
