/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// /*
//     Top-down dynamic programming: 
//     × Time Limit Exceeded
//     × 42/43 cases passed (N/A)
//     × testcase: '[[46],[43,61],[10,-16,3],...'
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return minimumTotal(triangle, 0, 0);
//     }

//     int minimumTotal(vector<vector<int>>& triangle, int i, int j)
//     {
//         if (i == triangle.size() - 1) {
//             return triangle[i][j];
//         }
//         int left = minimumTotal(triangle, i+1, j);
//         int right = minimumTotal(triangle, i+1, j+1);
//         return left < right ? left + triangle[i][j] : right + triangle[i][j];
//     }
// };

// /*
//     Bottom-up dynamic programming: 
//     √ Accepted
//     √ 43/43 cases passed (8 ms)
//     √ Your runtime beats 65.91 % of cpp submissions
//     √ Your memory usage beats 38.95 % of cpp submissions (9.9 MB)
//     √ Accepted
//     √ 43/43 cases passed (8 ms)
//     √ Your runtime beats 65.91 % of cpp submissions
//     √ Your memory usage beats 75 % of cpp submissions (9.7 MB)
//  */
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle)
//     {
//         if (triangle.empty()) { return 0; }
//         if (triangle.size() == 1) { return triangle[0][0]; }
//         vector<vector<int>> res(triangle);
//         for (int i = res.size() - 2; i >= 0; --i) {
//             for (int j = 0; j < res[i].size(); ++j) {
//                 res[i][j] = res[i][j] + std::min(res[i+1][j], res[i+1][j+1]);
//             }
//         }
//         return res[0][0];
//     }
// };

/*
    Optimized bottom-up dynamic programming: 
    √ Accepted
    √ 43/43 cases passed (8 ms)
    √ Your runtime beats 65.91 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.empty()) { return 0; }
        vector<int> res(triangle.back());
        for (int i = res.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                res[j] = triangle[i][j] + std::min(res[j], res[j+1]);
            }
        }
        return res[0];
    }
};