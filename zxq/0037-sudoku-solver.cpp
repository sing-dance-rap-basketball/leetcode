/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
// class Solution {
// public:
//     int char2int(char c) 
//     {
//         return 1 << (c - '1');
//     }
//     char int2char(int i)
//     {
//         int result = 0;
//         while (i != 1) {
//             i >>= 1;
//             ++result;
//         }
//         return '1' + result;
//     }
//     void update(vector<vector<char>>& board, vector<vector<int>>& infer, int row, int col)
//     {
//         int k = infer[row][col];
//         // update row
//         for (int j = 0; j < 9; ++j) {
//             if (j == col) { continue; }
//             if (board[row][j] == '.' && infer[row][j] & k != 0) {
//                 infer[row][j] -= k;
//             }
//         }
//         // update column
//         for (int i = 0; i < 9; ++i) {
//             if (i == row) { continue; }
//             if (board[i][col] == '.' && infer[i][col] & k != 0) {
//                 infer[i][col] -= k;
//             }
//         }
//         // update block
//         for (int i = row/3*3; i < row/3*3+3; ++i) {
//             if (i == row) { continue; }
//             for (int j = col/3*3; j < col/3*3+3; ++j) {
//                 if (j == col) { continue; }
//                 if (board[i][j] == '.' && infer[i][j] & k != 0) {
//                     infer[i][j] -= k;
//                 }
//             }
//         }
//         return;
//     }
//     void solveSudoku(vector<vector<char>>& board) 
//     {
//         vector<int> tempRow(9, 511);
//         vector<vector<int>> infer(9, tempRow);
//         int filled = 0;
//         char tempC;
//         int tempI;
//         // initialize
//         for (int i = 0; i < 9; ++i) {
//             for (int j = 0; j < 9; ++j) {
//                 if ((tempC = board[i][j]) != '.') {
//                     infer[i][j] = char2int(tempC);
//                     ++filled;
//                 }
//             }
//         } 
//         // update
//         while (filled < 30) {
//             for (int i = 0; i < 9; ++i) {
//                 for (int j = 0; j < 9; ++j) {
//                     if (board[i][j] != '.') {
//                         update(board, infer, i, j);
//                     }
//                     else {
//                         tempI = infer[i][j];
//                         if (tempI & (tempI - 1) == 0) {
//                             board[i][j] = int2char(tempI);
//                             ++filled;
//                             update(board, infer, i, j);
//                         }
//                     }
//                 }
//             }
//         }
//         return;
//     }
// };

class Solution {
public:
    int char2int(char c) 
    {
        return 1 << (c - '1');
    }
    char int2char(int i)
    {
        int result = 0;
        while (i != 1) {
            i >>= 1;
            ++result;
        }
        return '1' + result;
    }
    void update(vector<vector<char>>& board, vector<vector<int>>& infer, int row, int col)
    {
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        vector<int> tempRow(9, 511);
        vector<vector<int>> infer(9, tempRow);
        int filled = 0;
        char tempC;
        int tempI;
        // initialize
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ((tempC = board[i][j]) != '.') {
                    infer[i][j] = char2int(tempC);
                    ++filled;
                }
            }
        } 
        // update
        while (filled < 30) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        update(board, infer, i, j);
                    }
                    else {
                        tempI = infer[i][j];
                        if (tempI & (tempI - 1) == 0) {
                            board[i][j] = int2char(tempI);
                            ++filled;
                            update(board, infer, i, j);
                        }
                    }
                }
            }
        }
        return;
    }
};