/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// /*
//     √ Accepted
//     √ 80/80 cases passed (428 ms)
//     √ Your runtime beats 27.42 % of cpp submissions
//     √ Your memory usage beats 92 % of cpp submissions (10.3 MB)
//  */
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int res = 0;
//         int len = nums.size();
//         std::vector<int> left_sum(len, 0);
//         left_sum[0] = nums[0];
//         if (left_sum[0] == k) { ++res; }
//         for (int i = 1; i < len; ++i) {
//             left_sum[i] = left_sum[i-1] + nums[i];
//             if (left_sum[i] == k) { ++res; }
//         }
//         for (int i = 1; i < len; ++i) {
//             int target = k + left_sum[i-1];
//             for (int j = i; j < len; ++j) {
//                 if (left_sum[j] == target) {
//                     ++res;
//                 }
//             }
//         }
//         return res;
//     }
// };

/*
    √ Accepted
    √ 80/80 cases passed (44 ms)
    √ Your runtime beats 54.15 % of cpp submissions
    √ Your memory usage beats 25.34 % of cpp submissions (18.1 MB)
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        std::unordered_map<int, int> umap {};
        umap[0] = 1;
        int sum = 0;
        for (int n : nums) {
            sum += n;
            res += umap[sum - k];
            ++umap[sum];
        }
        return res;
    }
};