/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// /*
//   √ 50/50 cases passed (1388 ms)
//   √ Your runtime beats 5.08 % of cpp submissions
//   √ Your memory usage beats 78.09 % of cpp submissions (9.7 MB)
// */
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int res = 0;
//         for (int i = height.size()-1; i >= 1; --i) {
//             for (int j = i-1; j >= 0; --j) {
//                 int containWater = std::min(height[i], height[j]) * (i - j);
//                 if (containWater > res) {
//                     res = containWater;
//                 }
//             }
//         }
//         return res;
//     }
// };

// /*
//   √ 50/50 cases passed (604 ms)
//   √ Your runtime beats 19.21 % of cpp submissions
//   √ Your memory usage beats 15.78 % of cpp submissions (9.9 MB)
//   √ 50/50 cases passed (608 ms)
//   √ Your runtime beats 19.2 % of cpp submissions
//   √ Your memory usage beats 84.87 % of cpp submissions (9.6 MB)
// */
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int res = 0;
//         for (int i = height.size()-1; i >= 1; --i) {
//             for (int j = 0; j < i; ++j) {
//                 int containWater = std::min(height[i], height[j]) * (i - j);
//                 if (containWater > res) {
//                     res = containWater;
//                 }
//                 for (; j+1 < i && height[j+1] <= height[j]; ++j);
//             }
//             for (; i >= 2 && height[i-1] <= height[i]; --i);
//         }
//         return res;
//     }
// };

// /*
//   √ 50/50 cases passed (980 ms)
//   √ Your runtime beats 16.87 % of cpp submissions
//   √ Your memory usage beats 73.84 % of cpp submissions (9.7 MB)
// */
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int res = 0;
//         for (int len = height.size()-1; len >= 1; --len) {
//             int tempMax = 0;
//             for (int i = height.size()-1-len; i >= 0; --i) {
//                 if (height[i] > tempMax && height[i+len] > tempMax) {
//                     tempMax = std::min(height[i], height[i+len]);
//                 }
//             }
//             if (tempMax * len > res) {
//                 res = tempMax * len;
//             }
//         }
//         return res;
//     }
// };

// /*
//   √ 50/50 cases passed (200 ms)
//   √ Your runtime beats 21.8 % of cpp submissions
//   √ Your memory usage beats 68.63 % of cpp submissions (9.7 MB)
// */
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int res = 0;
//         int leftMax = height.front(), rightMax = height.back();
//         for (int i = height.size()-1; i >= 1; --i) {
//             rightMax = height[i];
//             for (int j = 0; j < i; ++j) {
//                 leftMax = height[j];
//                 int containWater = std::min(leftMax, rightMax) * (i - j);
//                 if (containWater > res) {
//                     res = containWater;
//                 }
//                 for (; j+1 < i && height[j+1] <= leftMax; ++j);
//             }
//             for (; i >= 2 && height[i-1] <= rightMax; --i);
//         }
//         return res;
//     }
// };

/*
  √ 50/50 cases passed (24 ms)
  √ Your runtime beats 35.43 % of cpp submissions
  √ Your memory usage beats 23.13 % of cpp submissions (9.9 MB)
  √ 50/50 cases passed (20 ms)
  √ Your runtime beats 76.25 % of cpp submissions
  √ Your memory usage beats 19.68 % of cpp submissions (9.9 MB)
  √ 50/50 cases passed (16 ms)
  √ Your runtime beats 97.08 % of cpp submissions
  √ Your memory usage beats 76.18 % of cpp submissions (9.7 MB)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = height.size()-1, j = 0;
        while (i > j) {
            int h = std::min(height[i], height[j]);
            res = std::max(res, h * (i - j));
            for (; i > j && height[i] <= h; --i);
            for (; j < i && height[j] <= h; ++j);
        }
        return res;
    }
};