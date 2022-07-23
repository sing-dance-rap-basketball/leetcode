/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// /*
//     √ Accepted
//     √ 44/44 cases passed (28 ms)
//     √ Your runtime beats 29.72 % of cpp submissions
//     √ Your memory usage beats 38.41 % of cpp submissions (11.1 MB)
//  */
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         return nums[(0+nums.size()) / 2];
//     }
// };

/*
    Boyer-Moore majority vote algorithm: 
    √ Accepted
    √ 44/44 cases passed (16 ms)
    √ Your runtime beats 96.98 % of cpp submissions
    √ Your memory usage beats 73.99 % of cpp submissions (11 MB)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for (int n : nums) {
            if (count == 0) {
                majority = n;
                ++count;
            }
            else {
                if (majority != n) { --count; }
                else { ++count; }
            }
        }
        return majority;
    }
};