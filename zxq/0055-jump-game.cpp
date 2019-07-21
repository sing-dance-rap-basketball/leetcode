/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// /*
//     Original solution: 
//     × Time Limit Exceeded
//     × 74/75 cases passed (N/A)
//     × testcase: '[25000,24999,24998,24997,24996, ... ,4,3,2,1,1,0,0]
//     × answer: 
//     × expected_answer: 
//     × stdout:
// */
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if (nums.empty()) { return false; }
//         vector<bool> isCanJump(nums.size(), false);
//         isCanJump.back() = true;
//         for (int i = isCanJump.size()-2; i >= 0; --i) {
//             for (int j = 1; j <= nums[i]; ++j) {
//                 if (isCanJump[i+j]) {
//                     isCanJump[i] = true;
//                 }
//             }
//             if (i <= nums[0] && isCanJump[i]) {
//                 return true;
//             }
//         }
//         return isCanJump[0];
//     }
// };

// /*
//     Backtracking: 
//     × Time Limit Exceeded
//     × 74/75 cases passed (N/A)
//     × testcase: '[25000,24999,24998, ... ,3,2,1,1,0,0]'
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     bool canJumpFromPosition(vector<int>& nums, int pos)
//     {
//         if (pos == nums.size()-1) { return true; }
        
//         int jumpFurthest = std::min(pos + nums[pos], int(nums.size() - 1));
//         for (int i = jumpFurthest; i > pos; --i) {
//             if (canJumpFromPosition(nums, i)) {
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool canJump(vector<int>& nums) {
//         return this->canJumpFromPosition(nums, 0);
//     }
// };

// /*
//     Top-down Dynamic Programming: 
//     × Time Limit Exceeded
//     × 74/75 cases passed (N/A)
//     × testcase: '[25000,24999,24998, ... ,3,2,1,1,0,0]'
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     vector<char> memo;
//     bool canJumpFromPosition(vector<int>& nums, int pos) 
//     {
//         if (memo[pos] != 'u') {
//             return memo[pos] == 'g' ? true : false;
//         }

//         int furthest = std::min(pos + nums[pos], (int)nums.size() - 1);
//         for (int i = furthest; i > pos; --i) {
//             if (canJumpFromPosition(nums, i)) {
//                 memo[pos] = 'g';
//                 return true;
//             }
//         }

//         memo[pos] = 'b';
//         return false;
//     }
//     bool canJump(vector<int>& nums) {
//         memo.resize(nums.size(), 'u');
//         memo.back() = 'g';
//         return canJumpFromPosition(nums, 0);
//     }
// };

// /*
//     Bottom-up Dynamic Programming (similar to my original solution)
//     √ Accepted
//     √ 75/75 cases passed (500 ms)
//     √ Your runtime beats 14.15 % of cpp submissions
//     √ Your memory usage beats 42.75 % of cpp submissions (9.9 MB)
//  */
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         vector<char> memo(nums.size(), 'u');
//         memo.back() = 'g';

//         for (int i = nums.size()-2; i >= 0; --i) {
//             int furthest = std::min(i + nums[i], (int)nums.size()-1);
//             for (int j = i+1; j <= furthest; ++j) {
//                 if (memo[j] == 'g') {
//                     memo[i] = 'g';
//                     break;
//                 }
//             }
//         }

//         return memo[0] == 'g';
//     }
// };

/*
    Greedy: 
    √ Accepted
    √ 75/75 cases passed (12 ms)
    √ Your runtime beats 76.62 % of cpp submissions
    √ Your memory usage beats 89.56 % of cpp submissions (9.7 MB)
    √ Accepted
    √ 75/75 cases passed (8 ms)
    √ Your runtime beats 97.42 % of cpp submissions
    √ Your memory usage beats 99.92 % of cpp submissions (9.6 MB)
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int leftmostCanJump = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= leftmostCanJump) {
                leftmostCanJump = i;
            }
        }

        return leftmostCanJump == 0;
    }
};