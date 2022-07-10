/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // Accepted
    // 58/58 cases passed (490 ms)
    // Your runtime beats 87.4 % of cpp submissions
    // Your memory usage beats 82.34 % of cpp submissions (89.7 MB)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {return 0;}
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int rightEnd = INT_MIN;
        for (auto& interval : intervals) {
            if (interval[0] >= rightEnd) {
                rightEnd = interval[1];
            } else {
                ++count;
                rightEnd = min(rightEnd, interval[1]);
            }
        }
        return count;
    }
};
// @lc code=end

