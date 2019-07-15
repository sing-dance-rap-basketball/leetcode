/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        result.resize(matrix.size() * matrix[0].size());
        int p=0;
        while(r1 <= r2 && c1 <= c2) {
            for(int c = c1; c<=c2; c++) result[p++] = matrix[r1][c];
            for(int r = r1 + 1; r<=r2; r++) result[p++] = matrix[r][c2];
            if(r1<r2 && c1<c2) {
                for(int c = c2-1; c>c1; c--) result[p++] = matrix[r2][c];
                for(int r=r2; r>r1; r--) result[p++] = matrix[r][c1];
            }
            r1++; r2--;
            c1++; c2--;
        }
        return result;
    }
};

