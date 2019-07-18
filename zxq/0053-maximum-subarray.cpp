/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// /*
//   × Wrong Answer
//     × 187/202 cases passed (N/A)
//     × testcase: '[-1]'
//     × answer: 0
//     × expected_answer: -1
//     × stdout:
// */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = 0;
//         int currSum = 0;
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] >= 0) {
//                 currSum += nums[i];
//                 res = currSum > res ? currSum : res;
//             }
//             else {
//                 if (currSum + nums[i] <= 0) {
//                     currSum = 0;
//                 }
//                 else {
//                     currSum += nums[i];
//                 }
//             }
//         }
//         return res;
//     }
// };

// /*
//   O(n) solution: 
//   √ Accepted
//     √ 202/202 cases passed (8 ms)
//     √ Your runtime beats 79.14 % of cpp submissions
//     √ Your memory usage beats 20.79 % of cpp submissions (9.4 MB)
//   √ Accepted
//     √ 202/202 cases passed (8 ms)
//     √ Your runtime beats 79.14 % of cpp submissions
//     √ Your memory usage beats 40.34 % of cpp submissions (9.3 MB)
//   √ Accepted
//     √ 202/202 cases passed (4 ms)
//     √ Your runtime beats 99.02 % of cpp submissions
//     √ Your memory usage beats 39.31 % of cpp submissions (9.3 MB)
// */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.empty()) { return 0; }
//         int res = nums[0];
//         int currSum = nums[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             if (currSum <= 0) {
//                 currSum = 0;
//             }
//             currSum += nums[i];
//             res = currSum > res ? currSum : res;
//         }
//         return res;
//     }
// };

/*
  "divide and conquer" solution: 
  √ Accepted
    √ 202/202 cases passed (8 ms)
    √ Your runtime beats 79.14 % of cpp submissions
    √ Your memory usage beats 6.32 % of cpp submissions (9.5 MB)
  √ Accepted
    √ 202/202 cases passed (12 ms)
    √ Your runtime beats 20.74 % of cpp submissions
    √ Your memory usage beats 20.09 % of cpp submissions (9.4 MB)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums, int left, int right)
    {
        if (left == right) { return nums[left]; }
        int middle = (left + right) / 2;
        
        int leftMax = maxSubArray(nums, left, middle);
        int rightMax = maxSubArray(nums, middle+1, right);
        
        int temp = nums[middle];
        int middleLeftMax = temp;
        for (int i = middle-1; i >= left; --i) {
            temp += nums[i];
            middleLeftMax = temp > middleLeftMax ? temp : middleLeftMax;
        }
        temp = nums[middle+1];
        int middleRightMax = temp;
        for (int i = middle+2; i <= right; ++i) {
            temp += nums[i];
            middleRightMax = temp > middleRightMax ? temp : middleRightMax;
        }
        int middleMax = std::max(middleLeftMax + middleRightMax, 
                                std::max(middleLeftMax, middleRightMax));

        return std::max(middleMax, std::max(leftMax, rightMax));
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        return maxSubArray(nums, 0, nums.size()-1);
    }
};