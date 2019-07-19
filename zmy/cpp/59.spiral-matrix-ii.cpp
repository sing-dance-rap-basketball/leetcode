/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 1));
        int left, top, index;
        int right, bottom;
        left = top = index = 0;
        right = bottom = n-1;

        while(left <= right && top <= bottom) {
            for(int j = left; j<=right; j++) 
                result[top][j] = ++index;
            top++;

            for(int i = top; i<=bottom; i++) 
                result[i][right] = ++index;
            right --;

            for(int j = right; j>=left; j--) 
                result[bottom][j] = ++index;
            bottom --;

            for(int i = bottom; i>= top; i--) 
                result[i][left] = ++index;
            left ++;
        }
        return result;
    }
};

