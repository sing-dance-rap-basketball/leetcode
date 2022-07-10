/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// /*
//     Two-pass algorithm using counting sort
//     √ Accepted
//     √ 87/87 cases passed (4 ms)
//     √ Your runtime beats 76.66 % of cpp submissions
//     √ Your memory usage beats 78.75 % of cpp submissions (8.5 MB)
//     √ Accepted
//     √ 87/87 cases passed (0 ms)
//     √ Your runtime beats 100 % of cpp submissions
//     √ Your memory usage beats 76.85 % of cpp submissions (8.5 MB)
//  */
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<int> count(3, 0);
//         for (int i = nums.size()-1; i >= 0; --i) {
//             ++count[nums[i]];
//         }
//         int idx = 0;
//         for (int i = 0; i < count.size(); ++i) {
//             for (int j = 0; j < count[i]; ++j) {
//                 nums[idx++] = i;
//             }
//         }
//         return;
//     }
// };

/*
    One-pass algorithm
    √ Accepted
    √ 87/87 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 35.23 % of cpp submissions (8.6 MB)
    √ Accepted
    √ 87/87 cases passed (4 ms)
    √ Your runtime beats 76.66 % of cpp submissions
    √ Your memory usage beats 34.15 % of cpp submissions (8.6 MB)
    √ Accepted
    √ 87/87 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 47.52 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        for (; left+1 < right && nums[left+1] == 0; ++left);
        for (; right-1 > left && nums[right-1] == 2; --right);
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] == 0) {
                nums[i] = nums[++left];
                nums[left] = 0; 
            }
            else if (nums[i] == 2) {
                for (; right-1 > left && nums[right-1] == 2; --right);
                if (right <= i) { break; }
                if (nums[right-1] == 1) {
                    nums[i] = 1;
                    nums[--right] = 2;
                }
                else {  // nums[right-1] == 0
                    if (i == left+1) {
                        nums[++left] = 0;
                        nums[--right] = 2;
                    }
                    else if (i > left+1) {
                        nums[++left] = 0;
                        nums[i] = 1;
                        nums[--right] = 2;
                    }
                }
            }
        }
        return;
    }
};