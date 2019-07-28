/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// /*
//     √ Accepted
//     √ 146/146 cases passed (4 ms)
//     √ Your runtime beats 80.66 % of cpp submissions
//     √ Your memory usage beats 57.52 % of cpp submissions (8.8 MB)
//  */
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         return nums[0];
//     }
// };

/*
    √ Accepted
    √ 146/146 cases passed (4 ms)
    √ Your runtime beats 80.66 % of cpp submissions
    √ Your memory usage beats 62.04 % of cpp submissions (8.7 MB)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() <= nums.back()) { return nums.front(); }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[m+1]) { return nums[m+1]; }
            else {
                if (nums[m] >= nums[l]) {
                    l = m + 1;
                }
                else {
                    if (nums[m] < nums[m-1]) { return nums[m]; }
                    else { r = m - 1; }
                }
            }
        }
        return l;   // not needed
    }
};