/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// /*
//     √ Accepted
//     √ 220/220 cases passed (308 ms)
//     √ Your runtime beats 18.17 % of cpp submissions
//     √ Your memory usage beats 50 % of cpp submissions (8.8 MB)
//  */
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         int len = nums.size();
//         int res = 0;
//         int k, l, m;
//         for (k = 0; k < nums.size() && nums[k] == 0; ++k);
//         for (; k < len - 2; ++k) {
//             for (l = k+1; l < len - 1; ++l) {
//                 int two_sides_sum = nums[k] + nums[l];
//                 for (m = l+1; m < len; ++m) {
//                     if (nums[m] < two_sides_sum) {
//                         ++res;
//                     }
//                     else {
//                         break;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

/*
    √ Accepted
    √ 220/220 cases passed (12 ms)
    √ Your runtime beats 93.37 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = 0;
        int k, l, m;
        for (k = 0; k < nums.size() && nums[k] == 0; ++k);
        for (; k < len - 2; ++k) {
            l = k + 1;
            m = l + 1;
            for (; l < len - 1; ++l) {
                int two_sides_sum = nums[k] + nums[l];
                for (; m < len && nums[m] < two_sides_sum; ++m);
                res += (m - l - 1);
            }
        }
        return res;
    }
};