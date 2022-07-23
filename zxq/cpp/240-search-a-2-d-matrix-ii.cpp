/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start

/**
 * Accepted
    129/129 cases passed (144 ms)
    Your runtime beats 53.66 % of cpp submissions
    Your memory usage beats 35.32 % of cpp submissions (10.9 MB)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto& m = matrix;
        if (m.empty() || m[0].empty())
        {
            return false;
        }
        
        int minR = 0, maxR = m.size() - 1;
        int minC = 0, maxC = m[0].size() - 1;
        while (minR <= maxR && minC <= maxC) 
        {
            int rt = m[minR][maxC]; // right top
            if (rt < target) 
            {
                ++minR;
            }
            else if (rt > target)
            {
                --maxC;
            }
            else
            {
                return true;
            }
            
            int lb = m[maxR][minC]; // left bottom
            if (lb < target)
            {
                ++minC;
            }
            else if (lb > target)
            {
                --maxR;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};
// @lc code=end

