/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  // // Time Limit Exceeded
  // // 47/49 cases passed (N/A)
  // int findMinArrowShots(vector<vector<int>>& points)
  // {
  //     if (points.size() == 1) {
  //         return 1;
  //     }
  //     sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
  //     return a[0] < b[0]; });

  //     int res = 1;
  //     int i = 0, j = 1;
  //     int rightEnd = points[i][1];
  //     while (i < points.size() && j < points.size()) {
  //         if (rightEnd >= points[j][0]) {
  //             if (rightEnd > points[j][1]) {
  //                 rightEnd = points[j][1];
  //             } // *
  //             ++j;
  //         } else {
  //             i = j;
  //             rightEnd = points[i][1]; // *
  //             j = i + 1;
  //             ++res;
  //         }
  //     }
  //     return res;
  // }

  // // Time Limit Exceeded
  // // 47/49 cases passed (N/A)
  // int findMinArrowShots(vector<vector<int>> &points)
  // {
  //   if (points.size() == 1) { return 1; }
  //   sort(points.begin(), points.end(),
  //        [](vector<int> a, vector<int> b){ return a[0] < b[0]; });

  //   int count = 1;
  //   int arrow = INT_MAX;
  //   for (auto& p : points) {
  //     if (p[0] <= arrow) {
  //       arrow = min(arrow, p[1]);
  //     } else {
  //       ++count;
  //       arrow = p[1];
  //     }
  //   }
  //   return count;
  // }

  // Accepted
  // 49/49 cases passed (579 ms)
  // Your runtime beats 74.07 % of cpp submissions
  // Your memory usage beats 68.02 % of cpp submissions (89.8 MB)
  int findMinArrowShots(vector<vector<int>> &points)
  {
    if (points.size() == 1) { return 1; }
    sort(points.begin(), points.end());

    int count = 1;
    int arrow = INT_MAX;
    for (auto& p : points) {
      if (p[0] <= arrow) {
        arrow = min(arrow, p[1]);
      } else {
        ++count;
        arrow = p[1];
      }
    }
    return count;
  }
};
// @lc code=end
