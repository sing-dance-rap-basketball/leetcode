/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;
        for (auto i = std::begin(nums); i!= std::end(nums); i++) {
            if (mp.find(target - (*i)) != std::end(mp)) {
                return {mp[target - (*i)], std::distance(std::begin(nums), i)};
            } else {
                mp[*i] = std::distance(std::begin(nums), i);
            }
        }
        return {};
    }
};

