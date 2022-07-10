/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

/* 
    √ Accepted
    √ 285/285 cases passed (24 ms)
    √ Your runtime beats 97.14 % of cpp submissions
    √ Your memory usage beats 68.97 % of cpp submissions (9.7 MB)
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A);
        int l = 0, r = res.size() - 1;
        while (l < r) {
            for (; l < r && res[l] % 2 == 0; ++l);
            for (; l < r && res[r] % 2 == 1; --r);
            if (l < r) {
                std::swap(res[l], res[r]);
            }
        }
        return res;
    }
};

