/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

/*
√ Accepted
  √ 23/23 cases passed (24 ms)
  √ Your runtime beats 95.62 % of cpp submissions
  √ Your memory usage beats 18.14 % of cpp submissions (15.6 MB)
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> umap {};
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) != umap.end() && i - umap[nums[i]] <= k) {
                return true;
            }
            umap[nums[i]] = i;
        }
        return false;
    }
};

