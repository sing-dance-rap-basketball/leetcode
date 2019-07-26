/**
 * 54. Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 */
 
/**
 * Runtime: 4 ms, faster than 66.57% of C++ online submissions for Spiral Matrix.
 * Memory Usage: 8.6 MB, less than 67.92% of C++ online submissions for Spiral Matrix.
 * 就当它是个状态机吧……
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int up = 0, left = 0;
        int bottom = matrix.size() - 1;
        
        if (bottom < 0)
            return ret;
        
        int right = matrix[0].size() -1;
        
        int stateTable[4] ={1, 2, 3, 0};
        int state = 0;
        int num = (bottom + 1) * (right + 1), count = 0;
        int x = 0, y = 0;
        while (count < num) {
            ret.push_back(matrix[y][x]);
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