/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// /*
//     0(n*n): 
//     √ Accepted
//     √ 53/53 cases passed (420 ms)
//     √ Your runtime beats 6.17 % of cpp submissions
//     √ Your memory usage beats 95.36 % of cpp submissions (9.9 MB)
//  */
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for (int i = nums.size()-1; i >= 0; --i) {
//             for (int j = i-1; j >= 0; --j) {
//                 if (nums[j] == nums[i]) {
//                     return nums[i];
//                 }
//             }
//         }
//         return 0;
//     }
// };

// /*
//     Modify the array, then get it back
//     √ Accepted
//     √ 53/53 cases passed (8 ms)
//     √ Your runtime beats 97.81 % of cpp submissions
//     √ Your memory usage beats 98.63 % of cpp submissions (9.8 MB)
//  */
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int res = 0;
//         for (int i = nums.size()-1; i >= 0; --i) {
//             int idx = abs(nums[i]);
//             if (nums[idx] < 0) {
//                 res = idx;
//                 break;
//             }
//             else {
//                 nums[idx] = -nums[idx];
//             }
//         }
//         for (int& n : nums) {
//             n = abs(n);
//         }
//         return res;
//     }
// };

/*
    Binary search: 
    √ Accepted
    √ 53/53 cases passed (12 ms)
    √ Your runtime beats 75.98 % of cpp submissions
    √ Your memory usage beats 93.72 % of cpp submissions (9.9 MB)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size()-1;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int k : nums) {
                if (k <= mid) { ++count; }
            }
            if (count > mid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};