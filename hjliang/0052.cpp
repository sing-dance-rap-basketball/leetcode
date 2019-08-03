/**
 * 52. N-Queens II
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 */

/**
 * Runtime: 4 ms, faster than 83.37% of C++ online submissions for N-Queens II.
 * Memory Usage: 8.3 MB, less than 93.90% of C++ online submissions for N-Queens II.
 * 只要数量是不是有简化方法……
 */

class Solution {
public:
    int totalNQueens(int n) {
        int *pos = new int[n];
        int count = 0;
        NQueens(0,count,pos,n);
        return count;
    }
    
private:      
    void NQueens(int curRow, int &count,int *pos, int n) {
        if (curRow == n) {
            ++count;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            int row;
            for (row = 0; row < curRow; ++row) {            
                if (col == pos[row] || abs(curRow - row) == abs(col - pos[row])) 
                    break;
            }
            
            if (row == curRow) {
                pos[row] = col;
                NQueens(curRow+1,count,pos,n);
            }
        }
    }
};