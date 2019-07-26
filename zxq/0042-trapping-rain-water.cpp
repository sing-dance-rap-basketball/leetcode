/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// /*
//   √ 315/315 cases passed (8 ms)
//   √ Your runtime beats 70.97 % of cpp submissions
//   √ Your memory usage beats 76.25 % of cpp submissions (9 MB)
//   √ 315/315 cases passed (4 ms)
//   √ Your runtime beats 97.55 % of cpp submissions
//   √ Your memory usage beats 76.25 % of cpp submissions (9 MB)
// */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         int left = 0, right = height.size()-1;
//         while (left < right) {
//             for (; left < right && height[left] <= height[left+1]; ++left);
//             int fill = 0;
//             int i = left + 1;
//             for (; i <= right; ++i) {
//                 if (height[i] < height[left]) {
//                     fill += height[i];
//                 }
//                 else {
//                     res = res + (i - left - 1) * height[left] - fill;
//                     left = i;
//                     break;
//                 }
//             }
//             if (i > right) { break; }
//         }
//         while (left < right) {
//             for (; right > left && height[right] <= height[right-1]; --right);
//             int fill = 0;
//             for (int i = right - 1; i >= left; --i) {
//                 if (height[i] < height[right]) {
//                     fill += height[i];
//                 }
//                 else {
//                     res = res + (right - i - 1) * height[right] - fill;
//                     right = i;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };

// /*
//     Basic solution: 
//     √ Accepted
//     √ 315/315 cases passed (8 ms)
//     √ Your runtime beats 66.48 % of cpp submissions
//     √ Your memory usage beats 77.8 % of cpp submissions (9 MB)
//  */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.size() <= 2) { return 0; }
//         int res = 0;
//         vector<int> leftmax(height.size());
//         leftmax.front() = height.front();
//         vector<int> rightmax(height.size());
//         rightmax.back() = height.back();
//         for (int i = 1; i < height.size(); ++i) {
//             leftmax[i] = std::max(leftmax[i-1], height[i]);
//         }
//         for (int i = height.size()-2; i >= 0; --i) {
//             rightmax[i] = std::max(rightmax[i+1], height[i]);
//         }
//         for (int i = 0; i < height.size(); ++i) {
//             res += std::min(leftmax[i], rightmax[i]) - height[i];
//         }
//         return res;
//     }
// };

// /*
//     Two pointers:
//     √ Accepted
//     √ 315/315 cases passed (4 ms)
//     √ Your runtime beats 97 % of cpp submissions
//     √ Your memory usage beats 76.73 % of cpp submissions (9 MB)
//  */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         // int l = 0, r = height.size()-1, level = 0, water = 0;
//         // while (l < r) {
//         //     int lower = height[height[l] < height[r] ? l++ : r--];
//         //     level = max(level, lower);
//         //     water += level - lower;
//         // }
//         // return water;
//         if (height.size() <= 2) { return 0; }
//         int res = 0;
//         int l = 0, r = height.size() - 1;
//         int lMax = 0, rMax = 0;
//         while (l < r) {
//             if (height[l] < height[r]) {
//                 height[l] > lMax ? lMax = height[l] : res += (lMax - height[l]);
//                 ++l;
//             }
//             else {
//                 height[r] > rMax ? rMax = height[r] : res += (rMax - height[r]);
//                 --r;
//             }
//         }
//         return res;
//     }
// };

/*
    Stack (similar to my original solution): 
    √ Accepted
    √ 315/315 cases passed (4 ms)
    √ Your runtime beats 97 % of cpp submissions
    √ Your memory usage beats 12.61 % of cpp submissions (9.4 MB)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};