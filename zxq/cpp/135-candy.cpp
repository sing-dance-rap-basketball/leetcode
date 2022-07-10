/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // Accepted
    // 48/48 cases passed (18 ms)
    // Your runtime beats 97.45 % of cpp submissions
    // Your memory usage beats 75.16 % of cpp submissions (17.7 MB)
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> res(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if ((ratings[i-1] < ratings[i]) && (res[i-1] >= res[i])) {
                res[i] = res[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && res[i] <= res[i+1]) {
                res[i] = res[i+1] + 1;
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }

};
// @lc code=end

