/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

/*
    Time Limit Exceeded
 */
// class Solution {
// public:
//     bool isSame(vector<int>& sol1, vector<int>& sol2)
//     {
//         return sol1[0] == sol2[0] && sol1[1] == sol2[1];
//         // if (sol1[0] != sol1[1]) {
//         //     bool flag = false, flag_ = false;
//         //     for (int j : sol2) {
//         //         if (j == sol1[0]) { flag = true; }
//         //         else if (j == sol1[1]) { flag_ = true; }
//         //     }
//         //     return flag && flag_;
//         // }
//         // else { // sol1[0] == sol1[1]
//         //     if (sol1[0] == 0) {
//         //         return sol2[0] == 0 && sol2[1] == 0;
//         //     }
//         //     else {
//         //         bool flag = false, flag_ = false;
//         //         for (int j : sol2) {
//         //             if (j == sol1[1]) { flag = true; }
//         //             else if (j == sol1[2]) { flag_ = true; }
//         //         }
//         //         return flag && flag_;
//         //     }
//         // }
//         // return false;
//     }
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         int len = nums.size();
//         for (int i = 0; i < len - 2; ++i) {
//             for (int j = i+1; j < len -1; ++j) {
//                 int target = 0 - nums[i] - nums[j];
//                 for (int k = j+1; k < len; ++k) {
//                     if (nums[k] == target) {
//                         vector<int> temp{nums[i], nums[j], nums[k]};
//                         sort(temp.begin(), temp.end());
//                         bool flag = true;
//                         for (auto& vec : result) {
//                             if (isSame(vec, temp)) {
//                                 flag = false;
//                                 break;
//                             }
//                         }
//                         if (flag) {
//                             result.push_back(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

/*
  √ 313/313 cases passed (112 ms)
  √ Your runtime beats 45.41 % of cpp submissions
  √ Your memory usage beats 45 % of cpp submissions (15.6 MB)
  √ 313/313 cases passed (108 ms)
  √ Your runtime beats 52.29 % of cpp submissions
  √ Your memory usage beats 43.89 % of cpp submissions (15.7 MB)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < len-2; ) {
            int j = i+1, k = len-1;
            int target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    for (j += 1; nums[j-1] == nums[j] && j < k; ++j);
                }
                else if (nums[j] + nums[k] > target) {
                    for (k -= 1; nums[k] == nums[k+1] && j < k; --k);
                }
                else {
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    for (j += 1; nums[j-1] == nums[j] && j < k; ++j);
                    for (k -= 1; nums[k] == nums[k+1] && j < k; --k);
                }
            }
            for (i += 1; nums[i-1] == nums[i] && i < len-2; ++i);
        }
        return result;
    }
};