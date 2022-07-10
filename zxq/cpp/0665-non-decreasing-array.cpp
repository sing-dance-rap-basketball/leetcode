/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

/*
    √ Accepted
    √ 325/325 cases passed (32 ms)
    √ Your runtime beats 80.78 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (10.2 MB)
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                if (i == nums.size() - 1) {
                    return true;
                }
                if (i-1 == 0) {
                    for (int j = i+1; j < nums.size(); ++j) {
                        if (nums[j-1] > nums[j]) {
                            return false;
                        }
                    }
                    return true;
                }
                if (i-1 > 0 && nums[i-2] < nums[i-1]) {
                    for (int j = i+1; j < nums.size(); ++j) {
                        if (nums[j-1] > nums[j]) {
                            return false;
                        }
                    }
                    if (nums[i] < nums[i-2] && nums[i+1] < nums[i-1]) {
                        return false;
                    }
                    return true;
                }
                if (i-1 > 0 && nums[i-2] == nums[i-1]) {
                    if (nums[i-1] > nums[i+1]) {
                        return false;
                    }
                    for (int j = i+1; j < nums.size(); ++j) {
                        if (nums[j-1] > nums[j]) {
                            return false;
                        }
                    }
                    return true;
                } 
                break;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i-1] > nums[i]) {
//                 if (i == nums.size() - 1) {
//                     return true;
//                 }
//                 for (int j = i+1; j < nums.size(); ++j) {
//                     if (nums[j-1] > nums[j]) {
//                         return false;
//                     }
//                 }
//                 if (i-1 == 0) {
//                     return true;
//                 }
//                 if (nums[i] < nums[i-2] && nums[i+1] < nums[i-1]) {
//                     return false;
//                 }
//                 break;  // return true;
//             }
//         }
//         return true;
//     }
// };