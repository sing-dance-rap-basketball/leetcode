/**
 * 36. Valid Sudoku
 * Share
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * 		1.Each row must contain the digits 1-9 without repetition.
 * 		2.Each column must contain the digits 1-9 without repetition.
 * 		3.Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */

/**
 * Runtime: 8 ms, faster than 98.97% of C++ online submissions for Valid Sudoku.
 * Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Valid Sudoku.
 * 性能上有提升空间  判断正确性只需要每个单元访问一次
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        struct{
            unsigned char x;
            unsigned char y;
        }center[N] = {{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};

        for (int i = 0; i < N; ++i) {
            if(!checkrow(board, i))
                return false;
            if(!checkcol(board, i))
                return false;
            if(!checkblock(board, center[i].x, center[i].y))
                return false;
        }
        return true;
    }
    
private:
    const unsigned char N = 9;

    int ctoi(char num) 
    {
        if (num < '1' || num > '9')
            return 0;
        else        
            return num - '0';  
    }
    
    bool checkrow(vector<vector<char> >& board, int rowNo)
    {
        int tmp = 0;
        for (int i = 0; i <  N; ++i) {
            int n = ctoi(board[rowNo][i]);
            if (n == 0)
                continue;
            
            if (tmp & (1 << (n - 1)))
                return false;
            
            tmp |= (1 << (n - 1));
        }
        
        return true;
    }

    bool checkcol(vector<vector<char> >& board, int colNo)
    {
        int tmp = 0;
        for (int i = 0; i <  N; ++i) {
            int n = ctoi(board[i][colNo]);
            if (n == 0)
                continue;
            
            if (tmp & (1 << (n - 1)))
                return false;
            
            tmp |= (1 << (n - 1));
        }
        return true;
    }

    bool checkblock(vector<vector<char> >& board, int cx, int cy)
    {
        int tmp = 0;

        for (int x = cx - 1; x < cx - 1 + N/3; ++x) {
            for (int y = cy - 1; y < cy - 1 + N/3; ++y) {
                int n = ctoi(board[x][y]);
                if (n == 0)
                    continue;
                if (tmp & (1 << (n - 1)))
                    return false;
            
                tmp |= (1 << (n - 1));
            }
        }
        return true;
    }
};