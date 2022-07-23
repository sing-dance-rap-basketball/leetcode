/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// /*
//     Hash table: 
//     √ Accepted
//     √ 28/28 cases passed (160 ms)
//     √ Your runtime beats 11.57 % of cpp submissions
//     √ Your memory usage beats 6.52 % of cpp submissions (27.1 MB)
//  */
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> res {};
//         unordered_map<int, int> umap {};
//         for (int n : nums) {
//             if (umap.find(n) == umap.end()) {
//                 umap[n] = 1;
//             }
//             else {
//                 if (umap[n] == 1) {
//                     res.push_back(n);
//                 }
//                 ++umap[n];
//             }
//         }
//         return res;
//     }
// };

// /*
//     Radix sort: 
//     √ Accepted
//     √ 28/28 cases passed (116 ms)
//     √ Your runtime beats 67.06 % of cpp submissions
//     √ Your memory usage beats 13.04 % of cpp submissions (16 MB)
//     √ Accepted
//     √ 28/28 cases passed (112 ms)
//     √ Your runtime beats 87.05 % of cpp submissions
//     √ Your memory usage beats 11.96 % of cpp submissions (16.1 MB)
//  */
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> res {};
//         vector<int> bucket(nums.size(), 0);
//         for (int n : nums) {
//             if (bucket[n-1] == 1) {
//                 res.push_back(n);
//             }
//             ++bucket[n-1];
//         }
//         return res;
//     }
// };

/*
    √ Accepted
    √ 28/28 cases passed (116 ms)
    √ Your runtime beats 67.06 % of cpp submissions
    √ Your memory usage beats 88.04 % of cpp submissions (14.9 MB)
    √ Accepted
    √ 28/28 cases passed (120 ms)
    √ Your runtime beats 37.4 % of cpp submissions
    √ Your memory usage beats 95.65 % of cpp submissions (14.8 MB)
    √ Accepted
    √ 28/28 cases passed (116 ms)
    √ Your runtime beats 67.06 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (14.7 MB)
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res {};
        int n = nums.size();
        for (int k : nums) {
            nums[(k-1) % n] += n;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 2 * n) {
                res.push_back(i+1);
            }
            nums[i] %= n;
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> res;

//         for (auto n: nums) {
//             n = abs(n);
//             nums[n - 1] = -nums[n - 1];
//             if (nums[n - 1] > 0)
//                 res.push_back(n);
//         }
//         return res;
//     }
// };