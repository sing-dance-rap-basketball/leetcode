/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start

/**
 * Accepted
    88/88 cases passed (56 ms)
    Your runtime beats 13.35 % of cpp submissions
    Your memory usage beats 95 % of cpp submissions (10.5 MB)
 */
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         if (nums.size() < 2) {
//             return false;
//         }

//         vector<long> sums(nums.size());
//         if (k == 0) {
//             sums[0] == nums[0];
//             for (int i = 1; i < sums.size(); ++i) {
//                 sums[i] = sums[i-1] + nums[i];
//                 if (sums[i] == 0) {
//                     return true;
//                 }
//             }
//         }
//         else {
//             sums[0] = nums[0] % k;
//             for (int i = 1; i < sums.size(); ++i) {
//                 sums[i] = (sums[i-1] + nums[i]) % k;
//                 if (sums[i] == 0) {
//                     return true;
//                 }
//             }
//         }

//         for (int i = 0; i < sums.size() - 2; ++i) {
//             for (int j = i + 2; j < sums.size(); ++j) {
//                 if (sums[i] == sums[j]) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

/**
 * Accepted
    88/88 cases passed (28 ms)
    Your runtime beats 83.73 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (9.7 MB)
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }

        k = k >= 0 ? k : -k;
        unordered_map<long, int> umap;
        // long curr = k == 0 ? nums[0] : nums[0] % k;
        // long pre = curr;
        // for (int i = 1; i < nums.size(); ++i) {
        //     curr += nums[i];
        //     if (k != 0) {
        //         curr %= k;
        //     }
        //     if (curr == 0 || umap.count(curr) > 0) {
        //         return true;
        //     }
        //     ++umap[pre];
        //     pre = curr;
        // }

        // 改进
        long curr = 0, pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr += nums[i];
            if (k != 0) {
                curr %= k;
            }
            if (umap.count(curr) > 0) {
                return true;
            }
            ++umap[pre];
            pre = curr;
        }

        return false;
    }
};

// @lc code=end

