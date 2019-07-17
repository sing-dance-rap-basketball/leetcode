/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

/*
  √ 315/315 cases passed (8 ms)
  √ Your runtime beats 70.97 % of cpp submissions
  √ Your memory usage beats 76.25 % of cpp submissions (9 MB)
  √ 315/315 cases passed (4 ms)
  √ Your runtime beats 97.55 % of cpp submissions
  √ Your memory usage beats 76.25 % of cpp submissions (9 MB)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            for (; left < right && height[left] <= height[left+1]; ++left);
            int fill = 0;
            int i = left + 1;
            for (; i <= right; ++i) {
                if (height[i] < height[left]) {
                    fill += height[i];
                }
                else {
                    res = res + (i - left - 1) * height[left] - fill;
                    left = i;
                    break;
                }
            }
            if (i > right) { break; }
        }
        while (left < right) {
            for (; right > left && height[right] <= height[right-1]; --right);
            int fill = 0;
            for (int i = right - 1; i >= left; --i) {
                if (height[i] < height[right]) {
                    fill += height[i];
                }
                else {
                    res = res + (right - i - 1) * height[right] - fill;
                    right = i;
                    break;
                }
            }
        }
        return res;
    }
};

// int trap(vector<int>& height) {
//     int l = 0, r = height.size()-1, level = 0, water = 0;
//     while (l < r) {
//         int lower = height[height[l] < height[r] ? l++ : r--];
//         level = max(level, lower);
//         water += level - lower;
//     }
//     return water;
// }