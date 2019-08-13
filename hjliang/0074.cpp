/**
 * 74. Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 */

/**
 * Runtime: 8 ms, faster than 94.23% of C++ online submissions for Search a 2D Matrix.
 * Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int index = 0;
        for(index = 0; index < matrix.size(); ++index) {
            if (matrix[index][0] <= target && matrix[index][n-1] >= target)
                break;
        }
        if (index == matrix.size()) return false;
        
        cout << "index:" << index << endl;
        int left = 0, right = matrix[0].size() - 1;
        while(left <= right) {
            cout << left << " " << right << endl;
            int mid = (left + right) /2;
            if (matrix[index][mid] == target)
                return true;
            else if (matrix[index][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};