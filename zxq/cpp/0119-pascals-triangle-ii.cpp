/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

/*
    √ Accepted
    √ 34/34 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 62.11 % of cpp submissions (8.5 MB)
 */
class Solution {
public:
    int combination(int n, int k)
    {
        long res = 1;    // avoid signed integer overflow
        for (int i = n, j = 1; j <= k; --i, ++j) {
            res = res * i / j;  
        }
        return (int)res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex / 2; ++i) {
            res[i] = combination(rowIndex, i);
        }
        for (int i = rowIndex / 2 + 1; i < rowIndex; ++i) {
            res[i] = res[rowIndex - i];
        }
        return res;
    }
};

