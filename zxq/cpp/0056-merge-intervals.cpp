/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// /*
// √ Accepted
//   √ 169/169 cases passed (16 ms)
//   √ Your runtime beats 91.63 % of cpp submissions
//   √ Your memory usage beats 70.79 % of cpp submissions (12.2 MB)
// √ Accepted
//   √ 169/169 cases passed (20 ms)
//   √ Your runtime beats 76.17 % of cpp submissions
//   √ Your memory usage beats 62.69 % of cpp submissions (12.3 MB)
// √ Accepted
//   √ 169/169 cases passed (12 ms)
//   √ Your runtime beats 99.37 % of cpp submissions
//   √ Your memory usage beats 69.83 % of cpp submissions (12.2 MB)
// */
// class Solution {
// public:
//     // static bool compareInterval(vector<int>& v1, vector<int>& v2)
//     // {
//     //     return v1[0] < v2[0];
//     // }
//     static bool compareInterval(vector<int>& v1, vector<int>& v2)
//     {
//         return v1[0] < v2[0];
//     }
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         if (intervals.empty()) { return res; }
//         else { 
//             std::sort(intervals.begin(), intervals.end(), 
//                         Solution::compareInterval);
//             res.push_back(intervals[0]); 
//         }

//         for (auto& v : intervals) {
//             if (v[0] <= res.back()[1]) {
//                 if (v[1] > res.back()[1]) {
//                     res.back()[1] = v[1];
//                 }
//             }
//             else {
//                 res.push_back(v);
//             }
//         }   
//         return res;
//     }
// };

/*
√ Accepted
  √ 169/169 cases passed (8 ms)
  √ Your runtime beats 99.98 % of cpp submissions
  √ Your memory usage beats 54.56 % of cpp submissions (12.4 MB)
√ Accepted
  √ 169/169 cases passed (16 ms)
  √ Your runtime beats 91.63 % of cpp submissions
  √ Your memory usage beats 71.91 % of cpp submissions (12.2 MB)
√ Accepted
  √ 169/169 cases passed (20 ms)
  √ Your runtime beats 76.17 % of cpp submissions
  √ Your memory usage beats 61.7 % of cpp submissions (12.3 MB)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) { return res; }
        else { 
            std::sort(intervals.begin(), intervals.end(), 
                        [](vector<int>& v1, vector<int>& v2){ return v1[0]<v2[0]; });
            res.push_back(intervals[0]); 
        }

        for (auto& v : intervals) {
            if (v[0] <= res.back()[1]) {
                if (v[1] > res.back()[1]) {
                    res.back()[1] = v[1];
                }
            }
            else {
                res.push_back(v);
            }
        }   
        return res;
    }
};