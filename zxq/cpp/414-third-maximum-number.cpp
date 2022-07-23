/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

/*
    √ Accepted
    √ 26/26 cases passed (4 ms)
    √ Your runtime beats 98.86 % of cpp submissions
    √ Your memory usage beats 98.72 % of cpp submissions (9 MB)
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> res {};
        for (int n : nums) {
            if (res.size() == 3) {
                if (n > res[0]) {
                    res[2] = res[1];
                    res[1] = res[0];
                    res[0] = n;
                }
                else if (n < res[0] && n > res[1]) {
                    res[2] = res[1];
                    res[1] = n;
                }
                else if (n < res[1] && n > res[2]) {
                    res[2] = n;
                }
            }
            else if (res.size() == 2) {
                if (n > res[0]) {
                    res.push_back(res[1]);
                    res[1] = res[0];
                    res[0] = n;
                }
                else if (n < res[0] && n > res[1]) {
                    res.push_back(res[1]);
                    res[1] = n;
                }
                else if (n < res[1]) {
                    res.push_back(n);
                }
            }
            else if (res.size() == 1) {
                if (n > res[0]) {
                    res.push_back(res[0]);
                    res[0] = n;
                }
                else if (n < res[0]) {
                    res.push_back(n);
                }
            }
            else if (res.empty()) {
                res.push_back(n);
            }
        }
        if (res.size() < 3) { return res[0]; }
        return res[2];
    }
};

