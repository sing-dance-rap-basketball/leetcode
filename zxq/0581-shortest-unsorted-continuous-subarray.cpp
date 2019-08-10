/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// /*
//     × Wrong Answer
//     × 218/307 cases passed (N/A)
//     × testcase: '[1,3,5,4,2]'
//     × answer: 3
//     × expected_answer: 4
//     × stdout:
//  */
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int l = -1, r = nums.size();
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] >= nums[i-1]) {
//                 continue;
//             }
//             else {
//                 int j = i - 1;
//                 for (; j >= 0; --j) {
//                     if (nums[i] < nums[j]) {
//                         continue;
//                     }
//                     else {
//                         break;
//                     }
//                 }
//                 l = j + 1;
//                 break;
//             }
//         }
//         if (l == -1) {
//             return 0;
//         }
//         for (int i = nums.size()-2; i >= 0; --i) {
//             if (nums[i] <= nums[i+1]) {
//                 continue;
//             }
//             else {
//                 int j = i + 1;
//                 for (; j < nums.size(); ++j) {
//                     if (nums[i] > nums[j]) {
//                         continue;
//                     }
//                     else {
//                         break;
//                     }
//                 }
//                 r = j - 1;
//                 break;
//             }
//         }
//         return (r - l + 1);
//     }
// };

/*
    √ Accepted
    √ 307/307 cases passed (36 ms)
    √ Your runtime beats 76 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (10.3 MB)
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, r = nums.size();
        int li = 1;
        for (; li < nums.size(); ++li) {
            if (nums[li] >= nums[li-1]) {
                continue;
            }
            else {
                int min_idx = li;
                for (int ii = min_idx + 1; ii < nums.size(); ++ii) {
                    if (nums[ii] < nums[min_idx]) {
                        min_idx = ii;
                    }
                }
                int j = min_idx - 1;
                for (; j >= 0; --j) {
                    if (nums[min_idx] < nums[j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                l = j + 1;
                break;
            }
        }
        if (l == -1) {
            return 0;
        }
        --li;
        for (int ri = nums.size()-2; ri >= li; --ri) {
            if (nums[ri] <= nums[ri+1]) {
                continue;
            }
            else {
                int max_idx = ri;
                for (int ii = max_idx - 1; ii >= li; --ii) {
                    if (nums[ii] > nums[max_idx]) {
                        max_idx = ii;
                    }
                }
                int j = max_idx + 1;
                for (; j < nums.size(); ++j) {
                    if (nums[max_idx] > nums[j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                r = j - 1;
                break;
            }
        }
        return (r - l + 1);
    }
};

