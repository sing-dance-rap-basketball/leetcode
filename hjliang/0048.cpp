/**
 * 48. Rotate Image
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 */

/**
 * Runtime: 4 ms, faster than 85.89% of C++ online submissions for Rotate Image.
 * Memory Usage: 9.1 MB, less than 42.10% of C++ online submissions for Rotate Image.
 * Note:
 *    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size()/2; ++j) {
                swap(matrix[i][j],matrix[i][matrix.size() - 1 - j]);
            }
        }
        
    }
};
