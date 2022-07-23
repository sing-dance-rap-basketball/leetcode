/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
/*
    Accepted
    32/32 cases passed (12 ms)
    Your runtime beats 78.59 % of cpp submissions
    Your memory usage beats 93.94 % of cpp submissions (9.2 MB)
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int min = nums[0], max = nums[0];
        for (int num : nums) {
            if (num < min) { min = num; }
            else if (num > max) { max = num; }
        }

        int l = min, r = max;
        while (l <= r) {
            int mid = (l + r) / 2;
            int nGreater = 0, nEqual = 0;
            for (int num : nums) {
                if (num > mid) { ++nGreater; }
                else if (num == mid) { ++nEqual; }
            }

            if (nGreater >= k) {
                l = mid + 1;
            }
            else {
                if (nGreater + nEqual >= k) { return mid; }
                else { r = mid - 1; }
            }
        }

        return l;
    }
};
// @lc code=end

// // @lc code=start
// /*
//     Accepted
//     32/32 cases passed (12 ms)
//     Your runtime beats 78.59 % of cpp submissions
//     Your memory usage beats 89.39 % of cpp submissions (9.2 MB)
//  */
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         std::sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };
// // @lc code=end