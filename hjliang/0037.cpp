/**
 * 没完成 只能解完全确定的数独
 */

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int left = readBoard(board);
        while (left) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (board[i][j] == '.') {
                        int res = checkPos(i,j);
                        if ( res != 0) { 
                            board[i][j] = res + '0';
                            updatePos(i, j, res);
                            left--;
                            //cout << i << " " << j << " " << res << endl; 
                        }
                    }
                }
            }
        }

        //printBoard(board);
    }
private:
    static const unsigned char N = 9;
    unsigned int record[N][N] = {{0}};

    void printBoard(vector<vector<char>> board) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j]  << " ";
            }
            cout << endl;
        }
    }

    int ctoi(char num) {
        if (num < '1' || num > '9')
            return 0;
        else        
            return num - '0';  
    }

    void updatePos(int x, int y, int value) {
        int i,j;
        int tmp = (value == 0) ? 0:(1 << value);
        
        for (i = 0; i < N; ++i)
            record[x][i] |= tmp;
        
        for (i = 0; i < N; ++i)
            record[i][y] |= tmp;

        int block_x = x/3,block_y = y/3;
        for (i = 0; i < N/3; ++i) 
            for (j = 0; j < N/3; ++j)
                record[block_x * 3 + i][block_y * 3 + j] |= tmp;    
    }

    int readBoard(vector<vector<char>> board) {
        int count = N * N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int tmp = ctoi(board[i][j]);
                if (tmp != 0) {
                    --count ;
                    updatePos(i,j,tmp);
                }     
            }
        }
        return count;
    }

    int checkPos(int x, int y) {
        int tmp = record[x][y];
        int sum = 0;
        for (int i = 9; i > 0; --i) {
            int num = (tmp >> i) & 1;
            sum += num;
        }

        if (sum == 8) {
            int i;
            for (i = 9; i > 0; --i) {
                if (((tmp >> i) & 1) == 0)
                    break;
            }
            return i;
        }

        return 0;
    }

};