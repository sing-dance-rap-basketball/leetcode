/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// /*
//     √ Accepted
//     √ 34/34 cases passed (272 ms)
//     √ Your runtime beats 11.45 % of cpp submissions
//     √ Your memory usage beats 84.95 % of cpp submissions (9.5 MB)
//  */
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k = k % nums.size();
//         for (int i = 0; i < k; ++i) {
//             int curr = nums.size() - k + i;
//             int temp = nums[curr];
//             for (int j = curr; j > i; --j) {
//                 nums[j] = nums[j-1];
//             }
//             nums[i] = temp;
//         }
//         return;
//     }
// };

// /*
//     √ Accepted
//     √ 34/34 cases passed (16 ms)
//     √ Your runtime beats 86.97 % of cpp submissions
//     √ Your memory usage beats 75.05 % of cpp submissions (9.5 MB)
//  */
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k = k % nums.size();
//         int len = nums.size();
//         vector<int> copy(nums);
//         for (int i = 0; i < nums.size(); ++i) {
//             nums[(i+k) % len] = copy[i];
//         }
//         return;
//     }
// };

/*
    √ Accepted
    √ 34/34 cases passed (16 ms)
    √ Your runtime beats 86.97 % of cpp submissions
    √ Your memory usage beats 88.07 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
        return;
    }
};