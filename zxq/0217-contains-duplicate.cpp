/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

/*
    √ Accepted
    √ 18/18 cases passed (44 ms)
    √ Your runtime beats 45.72 % of cpp submissions
    √ Your memory usage beats 40.1 % of cpp submissions (16.6 MB)
    √ Accepted
    √ 18/18 cases passed (36 ms)
    √ Your runtime beats 76.08 % of cpp submissions
    √ Your memory usage beats 60.42 % of cpp submissions (16.5 MB)
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) != umap.end()) {
                return true;
            }
            else {
                umap[nums[i]] = 1;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         return nums.size() > std::set<int>(nums.begin(), nums.end()).size();        
//     }
// };