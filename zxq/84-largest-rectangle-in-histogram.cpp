/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// /*
//     Divide and conquer: 
//     × Time Limit Exceeded
//     × 95/96 cases passed (N/A)
//     × testcase: '[1,1,1,1, ... ,1,1,1]
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         return largestRectangleArea(heights, 0, heights.size()-1);
//     }
//     int largestRectangleArea(vector<int>& heights, int left, int right) {
//         if (left > right) { return 0; }
//         if (left == right) { return heights[left]; }
//         int minIdx = left;
//         for (int i = left; i <= right; ++i) {
//             if (heights[i] < heights[minIdx]) {
//                 minIdx = i;
//             }
//         }
//         return std::max(heights[minIdx] * (right - left + 1), 
//                         std::max(largestRectangleArea(heights, left, minIdx-1), 
//                                     largestRectangleArea(heights, minIdx+1, right)));
//     }
// };

// /*
//     √ Accepted
//     √ 96/96 cases passed (848 ms)
//     √ Your runtime beats 6.47 % of cpp submissions
//     √ Your memory usage beats 88.52 % of cpp submissions (10.1 MB)
//  */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int curr = 0;
//         int res = 0;
//         vector<int> s {-1};   // similar to a stack
//         while (curr < heights.size()) {
//             for (int i = s.size()-1; i > 0; --i) {
//                 if (heights[curr] <= heights[s[i]]) {
//                     s.pop_back();
//                 }
//                 else { break; }
//             }
//             int w = curr - s.back();
//             int h = heights[curr];
//             if (w * h > res) { res = w * h; }
//             for (int i = s.size()-1; i > 0; --i) {
//                 w = curr - s[i-1];
//                 h = heights[s[i]];
//                 if (w * h > res) { res = w * h; }
//             }
//             s.push_back(curr++);
//         }
//         return res;
//     }
// };

// /*
//     × Wrong Answer
//     × 75/96 cases passed (N/A)
//     × testcase: '[3,6,5,7,4,8,1,0]'
//     × answer: 18
//     × expected_answer: 20
//     × stdout:
//  */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int res = 0;
//         stack<int> s {};
//         int curr = 0;
//         while (curr < heights.size()) {
//             while (!s.empty()) {
//                 if (heights[curr] > heights[s.top()]) {
//                     int area = heights[curr] * (curr - s.top());
//                     res = area > res ? area : res;
//                     s.push(curr++);
//                     break;
//                 }
//                 else {
//                     s.pop();
//                 }
//             }
//             if (s.empty()) {
//                 int area = heights[curr] * (curr + 1);
//                 res = area > res ? area : res;
//                 s.push(curr++);
//             }
//         }
//         while (!s.empty()) {
//             int h = heights[s.top()];
//             s.pop();
//             int w = s.empty() ? heights.size() : heights.size() - 1 - s.top();
//             int area = h * w;
//             res = area > res ? area : res;
//         }
//         curr = heights.size() - 1;
//         while (curr >= 0) {
//             while (!s.empty()) {
//                 if (heights[curr] > heights[s.top()]) {
//                     int area = heights[curr] * (s.top() - curr);
//                     res = area > res ? area : res;
//                     s.push(curr--);
//                     break;
//                 }
//                 else {
//                     s.pop();
//                 }
//             }
//             if (s.empty()) {
//                 int area = heights[curr] * (heights.size() - curr);
//                 res = area > res ? area : res;
//                 s.push(curr--);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights, int left, int right) {
        
    }
};