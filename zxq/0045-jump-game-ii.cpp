/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// /*
//     Time Limit Exceeded
// */
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int len = nums.size();
//         if (len <= 1) { return 0; }
//         vector<int> min_jumps(len, 0);
//         for (int i = len-2; i >= 0; --i) {
//             if (nums[i] == 0) {
//                 min_jumps[i] = len;
//                 continue;
//             }
//             if (i + nums[i] >= len - 1) {
//                 min_jumps[i] = 1;
//             }
//             else {
//                 int temp_min_jumps = len;
//                 for (int j = i+nums[i]; j > i; --j) {
//                     if (min_jumps[j] < temp_min_jumps) {
//                         temp_min_jumps = min_jumps[j];
//                     }
//                 }
//                 min_jumps[i] = (temp_min_jumps >= len) ? len : (temp_min_jumps + 1);
//             }
//         }
//         return min_jumps[0];
//     }
// };

/*
  √ 92/92 cases passed (8 ms)
  √ Your runtime beats 97.28 % of cpp submissions
  √ Your memory usage beats 14.3 % of cpp submissions (10.4 MB)
  √ 92/92 cases passed (12 ms)
  √ Your runtime beats 78.61 % of cpp submissions
  √ Your memory usage beats 16.95 % of cpp submissions (10.3 MB)
  √ 92/92 cases passed (12 ms)
  √ Your runtime beats 78.61 % of cpp submissions
  √ Your memory usage beats 26.27 % of cpp submissions (10.2 MB)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) { return 0; }
        if (nums[0] >= len-1) { return 1; }
        vector<int> min_jumps(len, 0);
        for (int i = len-2; i >= 0; --i) {
            if (nums[i] == 0) {
                min_jumps[i] = len;
                continue;
            }
            if (i + nums[i] >= len - 1) {
                min_jumps[i] = 1;
            }
            else {
                int temp_min_jumps = len;
                for (int j = i+nums[i]; j > i; --j) {
                    if (min_jumps[j] < temp_min_jumps) {
                        temp_min_jumps = min_jumps[j];
                    }
                }
                min_jumps[i] = (temp_min_jumps >= len) ? len : (temp_min_jumps + 1);
            }
            if (i <= nums[0] && min_jumps[i] == 1) {
                return 2;
            }
        }
        return min_jumps[0];
    }
};