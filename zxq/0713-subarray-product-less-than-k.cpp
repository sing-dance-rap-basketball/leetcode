/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// /*
//     √ Accepted
//     √ 84/84 cases passed (136 ms)
//     √ Your runtime beats 30.14 % of cpp submissions
//     √ Your memory usage beats 60 % of cpp submissions (18.3 MB)
//  */
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         if (k <= 1) { return 0; }
//         int count = 0;
//         int slow = 0, fast = 0;
//         int curr_prod = nums[0];
//         while (slow < nums.size()) {
//             if (fast < slow) {
//                 fast = slow - 1;
//             }
//             while (fast+1 < nums.size() && curr_prod * nums[fast+1] < k) {
//                 ++fast;
//                 curr_prod *= nums[fast];
//             }
//             if (slow <= fast) {
//                 count += (fast-slow+1);
//                 curr_prod /= nums[slow];
//             }
//             ++slow;
//         }
//         return count;
//     }
// };

/*
    √ Accepted
    √ 84/84 cases passed (128 ms)
    √ Your runtime beats 83.1 % of cpp submissions
    √ Your memory usage beats 70 % of cpp submissions (18.3 MB)
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) { return 0; }
        int count = 0;
        int slow = 0;
        int prod = 1;
        for (int fast = 0; fast < nums.size(); ++fast) {
            prod *= nums[fast];
            while (slow <= fast && prod >= k) {
                prod /= nums[slow++];
            }
            if (slow <= fast) {
                count += (fast - slow + 1);
            }
        }
        return count;
    }
};