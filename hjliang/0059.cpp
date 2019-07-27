/**
 * 59. Spiral Matrix II
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 */

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
 * Memory Usage: 8.9 MB, less than 58.86% of C++ online submissions for Spiral Matrix II.
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int stateTable[4] ={1, 2, 3, 0};
        int state = 0;
        int up = 0, left = 0;
        int bottom = n - 1;  
        int right = n -1;
        int num = n * n, count = 0;
        int x = 0, y = 0;
        
        while (count < num) {
            ret[y][x] = count + 1;
            ++count;
            switch (state) {
                case 0:
                    if (x == right) {
                        state = stateTable[state];
                        ++y;
                        ++up;
                    }
                    else
                        ++x;
                    break;
                case 1:
                    if (y == bottom) {
                        state = stateTable[state];
                        --right;
                        --x;
                    }
                    else
                        ++y;
                    break;
                case 2:
                    if (x == left) {
                        state = stateTable[state];
                        --bottom;
                        --y;
                    }
                    else
                        --x;
                    break;
                case 3:
                    if (y == up) {
                        state = stateTable[state];
                        ++left;
                        ++x;
                    }
                    else
                        --y;
                    break;
                default:
                    break;
            }
        }
        return ret;
    }
};